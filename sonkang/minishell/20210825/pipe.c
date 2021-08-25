#include "minishell.h"

void	pipe_execve(t_mini *mini)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		//if (execve(cmd, mini->buf, *envp) == -1)
		//	printf("minishell: %s: %s\n", cmd, strerror(errno));
		if (mini->pipe)
		{
			printf("mini->pipe : %d\n", mini->pipe);
			mini->pipe--;
			pipe_execve(mini);
		}
		exit(0);
	}
	if (pid > 0)
	{
		wait(&status);
		printf("parent : mini->pipe : %d\n", mini->pipe);
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
}

int		check_pipe(t_mini *mini)
{
	int		i;

	i = mini->first;
	if (ft_strncmp(mini->buf[i], "|", 2) == 0)
		return (mini->err.pipe);
	while (mini->buf[++i])
		if (ft_strncmp(mini->buf[i], "|", 2) == 0)
			mini->pipe++;
	if (mini->pipe)
	{
		pipe_execve(mini);
	}
	return (0);
}
