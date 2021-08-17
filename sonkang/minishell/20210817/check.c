#include "minishell.h"

void	ft_execve(t_mini *mini)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(mini->buf[0], mini->buf, 0) == -1)
			printf("minishell: %s\n", strerror(errno));
	}
	else if (pid > 0)
		wait(&status);
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
}

int	check_cmd(char *cmd, t_mini *mini)
{
	if (!ft_strncmp("echo", cmd, 5) || !ft_strncmp("ECHO", cmd, 5))
		;
	else if (!ft_strncmp("cd", cmd, 3) || !ft_strncmp("CD", cmd, 3))
		;
	else if (!ft_strncmp("pwd", cmd, 4) || !ft_strncmp("PWD", cmd, 4)) 
		;
	else if (!ft_strncmp("export", cmd, 7) || !ft_strncmp("EXPORT", cmd, 7))
		;
	else if (!ft_strncmp("unset", cmd, 6) || !ft_strncmp("UNSET", cmd, 6))
		;
	else if (!ft_strncmp("env", cmd, 4) || !ft_strncmp("ENV", cmd, 4))
		;
	else if (!ft_strncmp("exit", cmd, 5) || !ft_strncmp("EXIT", cmd, 5))
		;
	else if (ft_strchr(mini->buf[0], '/') != 0)
		ft_execve(mini);
	else
		return (-2);
	return (0);
}
