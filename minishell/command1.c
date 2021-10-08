#include "minishell.h"

void	ft_echo(t_mini *mini)
{
	int idx;
	int option;

	idx = mini->first;
	option = mini->first + 1;
	while (mini->buf[++idx] != 0 && *(mini->buf[idx]) == 0) 
		option++;
	idx = mini->first;
	while(mini->buf[++idx])
	{
		if (idx == option && \
				!ft_strncmp(mini->buf[option], "-n", 3))
			idx++;
		printf("%s", mini->buf[idx]);
		if (mini->buf[idx + 1] != 0 /*&& *(mini->buf[idx]) != 0*/)
			printf(" ");
		if (mini->buf[idx + 1] == 0 && \
				ft_strncmp(mini->buf[option], "-n", 3))
			printf("\n");
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
	int		idx;
	int		jdx;

	jdx = -1;
	while ((*mini->envp)[++jdx])
		if (!ft_strncmp((*mini->envp)[jdx], "PWD=", 4))
		{
			idx = -1;
			while ((*mini->envp)[++idx])
				if (!ft_strncmp((*mini->envp)[idx], "OLDPWD=", 7))
				{
					(*mini->envp)[idx] = ft_strdup(ft_strjoin("OLD", (*mini->envp)[jdx]));
					if (!(*mini->envp)[idx])
						return (mini->err.malloc);
				}
			(*mini->envp)[jdx] = ft_strdup(ft_strjoin("PWD=", getcwd(pwd, 1024)));
			//leak check
		}
	return (0);
}

int	ft_chdir(t_mini *mini)
{
	int		idx;
	char	*dest;
	int		ret;

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