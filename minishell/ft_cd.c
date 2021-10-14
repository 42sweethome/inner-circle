#include "minishell.h"

void	change_value(char *key, char *value, char **envp)
{
	char	*tmp;

	tmp = ft_strjoin(key, value);
	free(*envp);
	*envp = ft_strdup(tmp);
	free(tmp);
}

int	change_pwd(t_mini *mini)
{
	char	pwd[1024];
	int		idx;
	int		jdx;

	jdx = -1;
	while (mini->envp[++jdx])
	{
		if (!ft_strncmp(mini->envp[jdx], "PWD=", 4))
		{
			idx = -1;
			while (mini->envp[++idx])
			{
				if (!ft_strncmp(mini->envp[idx], "OLDPWD=", 7))
				{
					change_value("OLD", mini->envp[jdx], &(mini->envp[idx]));
					if (!mini->envp[idx])
						return (mini->err.malloc);
				}
			}
			change_value("PWD=", getcwd(pwd, 1024), &(mini->envp[jdx]));
		}
	}
	return (0);
}

int	only_cd(t_mini *mini)
{
	int		ret;
	char	*dest;

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
	chdir(dest);
	free(dest);
	if (change_pwd(mini))
		return (mini->err.malloc);
	return (1);
}

int	ft_chdir(t_mini *mini)
{
	int		idx;
	int		ret;

	mini->exit_stat = 0;
	if (mini->upper == 1)
		return (0);
	idx = mini->first;
	while (mini->buf[++idx] != 0 && *(mini->buf[idx]) == 0)
		;
	ret = 0;
	if (mini->buf[idx] == 0)
		ret = only_cd(mini);
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
	return (ret);
}
