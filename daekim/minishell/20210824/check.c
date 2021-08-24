#include "minishell.h"

void	ft_execve(t_mini *mini, char *cmd, char ***envp)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, mini->buf, *envp) == -1)
			printf("minishell: %s: %s\n", cmd, strerror(errno));
		exit(0);
	}
	if (pid > 0)
		wait(&status);
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
}

int	check_path(t_mini *mini, char *cmd)
{
	char	*temp;
	int		pid;
	int		status;
	int		idx;

	pid = fork();
	if (pid == 0)
	{
		idx = -1;
		while (mini->path[++idx])
		{
			temp = ft_strjoin(mini->path[idx], cmd);
			if (temp == NULL)
				exit(1);
			//free(mini->path[idx]);
			mini->path[idx] = temp;
			execve(mini->path[idx], mini->buf, 0);
		}
		cmd_err(cmd, mini->err.cmd, mini);
		exit(0);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (status == 256)
			return (mini->err.malloc);
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
	return (0);
}

int	check_cmd(char *cmd, t_mini *mini, char ***envp)
{
	if (!ft_strncmp("echo", cmd, 5) || !ft_strncmp("ECHO", cmd, 5))
		ft_echo(mini);
	else if (!ft_strncmp("cd", cmd, 3) || !ft_strncmp("CD", cmd, 3))
		ft_chdir(mini);
	else if (!ft_strncmp("pwd", cmd, 4) || !ft_strncmp("PWD", cmd, 4)) 
		ft_pwd();
	else if (!ft_strncmp("export", cmd, 7) || !ft_strncmp("EXPORT", cmd, 7))
	{
		if (ft_export(mini, envp) == mini->err.malloc)
			return (mini->err.malloc);
	}
	else if (!ft_strncmp("unset", cmd, 6) || !ft_strncmp("UNSET", cmd, 6))
		;
	else if (!ft_strncmp("env", cmd, 4) || !ft_strncmp("ENV", cmd, 4))
		ft_env(mini->envp);
	else if (!ft_strncmp("exit", cmd, 5) || !ft_strncmp("EXIT", cmd, 5))
		exit(0);
	else if (ft_strchr(cmd, '/') != 0)
		ft_execve(mini, cmd, envp);	
	else
		return (check_path(mini, cmd));
	return (0);
}
