#include "minishell.h"

int	check_option_n(t_mini *mini)
{
	int i;
	int j;

	i = mini->first;
	while (mini->buf[++i])
	{
		if (mini->buf[i][0] == '-')
		{
			j = 0;
			while (mini->buf[i][++j] == 'n')
				;
			if (mini->buf[i][j] == 0)
				mini->option_n++;
			else
				break ;
		}
		else
			break ;
	}
	return (mini->option_n);
}

void	ft_echo(t_mini *mini)
{
	int idx;

	idx = mini->first;
	while (mini->buf[++idx])
	{
		if (mini->upper == 1)
		{
			if (idx == mini->first + 1 && \
				!ft_strncmp(mini->buf[mini->first + 1], "-n", 3))
				idx++;
			if (mini->buf[idx] == 0)	
				break ;
			printf("%s", mini->buf[idx]);
			if (mini->buf[idx + 1] != 0)
				printf(" ");
			if (mini->buf[idx + 1] == 0 && \
				ft_strncmp(mini->buf[mini->first + 1], "-n", 3))
				printf("\n");
		}
		else
		{
			if (idx == mini->first + 1)
				idx += check_option_n(mini);
			if (mini->buf[idx] == 0)
				break ;
			printf("%s", mini->buf[idx]);
			if (mini->buf[idx + 1] != 0)
				printf(" ");
			if (mini->buf[idx + 1] == 0 && mini->option_n == 0)
				printf("\n");
		}
	}	
}

void	ft_pwd(void)//export구현 후 수정
{
	char pwd[1024];

	printf("%s\n", getcwd(pwd, 1024));
}

void	ft_env(char ***envp)
{
	int	idx;

	idx = -1;
	while ((*envp)[++idx])
		printf("%s\n", (*envp)[idx]);
}

int	change_pwd(t_mini *mini)
{
	char	pwd[1024];
	char	*tmp;
	int		idx;
	int		jdx;

	jdx = -1;
	while (mini->envp[++jdx])
		if (!ft_strncmp(mini->envp[jdx], "PWD=", 4))
		{
			idx = -1;
			while (mini->envp[++idx])
				if (!ft_strncmp(mini->envp[idx], "OLDPWD=", 7))
				{
					tmp = ft_strjoin("OLD", mini->envp[jdx]);
					free(mini->envp[idx]);
					mini->envp[idx] = ft_strdup(tmp);
					free(tmp);
					if (!mini->envp[idx])
						return (mini->err.malloc);
				}
			tmp = ft_strjoin("PWD=", getcwd(pwd, 1024));//leak
			free(mini->envp[jdx]);
			mini->envp[jdx] = ft_strdup(tmp);
			free(tmp);
		}
	return (0);
}

int	ft_chdir(t_mini *mini)
{
	int		idx;
	char	*dest;
	int		ret;

	if (mini->upper == 1)
	{
		mini->exit_stat = 0;
		return (0);
	}
	idx = mini->first;
	while (mini->buf[++idx] != 0 && *(mini->buf[idx]) == 0)
		;
	if (mini->buf[idx] == 0)
	{
		ret = ft_getenv(mini, &dest, "HOME");
		if (ret == mini->err.malloc)
			return (mini->err.malloc);
		else if (ret == 0)
		{
			printf("minishell: cd: HOME not set\n");
			free(dest);
			mini->exit_stat = 1;
			return (0);
		}
		chdir(dest);// 클러스터랑 좀 다른 것 같다고함
		free(dest);
		if (change_pwd(mini))
			return (mini->err.malloc);
	}
	else if (&(mini->buf[idx]) != 0 && chdir(mini->buf[idx]) == 0)
	{
		if (change_pwd(mini))
			return (mini->err.malloc);
	}
	else
	{
		printf("minishell: %s: %s\n", mini->buf[idx], strerror(errno));
		mini->exit_stat = 1;
		return (0);
	}
	mini->exit_stat = 0;
	return (0);
}