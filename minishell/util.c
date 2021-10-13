#include "minishell.h"

int	check_digit(char *arg)
{
	int	i;

	i = -1;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[++i])
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
	return (1);
}

void	rm_tmpfile(int cnt)
{
	int		i;
	char	*str;
	char	*tmp;

	i = -1;
	while (++i <= cnt)
	{
		str = ft_itoa(i);
		tmp = ft_strjoin("/tmp/.", str);
		unlink(tmp);
		free(tmp);
		free(str);
	}
}

int	ft_getenv(t_mini *mini, char **env, char *str)
{
	int		idx;
	int		len;
	int		cmp;

	idx = -1;
	len = ft_strlen(str);
	*env = 0;
	while (mini->envp[++idx])
	{	
		cmp = ft_strncmp(mini->envp[idx], str, len);
		if (cmp == 0)
		{
			if (mini->envp[idx][len] == '=')
			{
				*env = ft_strdup(&(mini->envp[idx][len + 1]));
				if (*env == 0)
					return (-1);
				return (1);
			}
		}
	}
	return (0);
}

void	cmd_err2(t_mini *mini, int err_num, char *cmd)
{
	if (err_num == mini->err.cmd)
	{
		mini->exit_stat = 127;
		printf("minishell: %s: command not found\n", cmd);
	}
	else if (err_num == mini->err.argv)
	{
		mini->exit_stat = 1;
		printf("minishell: %s: argument error\n", cmd);
	}
	else if (err_num == mini->err.redirect)
	{
		mini->exit_stat = 258;
		printf("minishell: syntax error near unexpected token `%.2s'\n", cmd);
	}
}

int	cmd_err(char *cmd, int err_num, t_mini *mini)
{
	if (err_num == mini->err.malloc || err_num == mini->err.path_malloc)
	{
		mini->exit_stat = 12;
		printf("minishell: malloc error\n");
		return (err_num);
	}
	else if (err_num == mini->err.quo)
	{
		mini->exit_stat = 127;
		printf("minishell: quotes are not closed\n");
	}
	else if (err_num == mini->err.pipe)
	{
		mini->exit_stat = 258;
		printf("minishell: syntax error near unexpected token `|'\n");
	}
	else
		cmd_err2(mini, err_num, cmd);
	return (-2);
}
