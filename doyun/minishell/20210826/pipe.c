#include "minishell.h"

void	pipe_execve(t_mini *mini)
{
	int		pid;
	int		status;
	int		fd[2];
	int		p_fd[2];

	pid = fork();
	pipe(fd);
	if (pid == 0)
	{
		if (mini->pipe)
		{
			dup2(fd[0], 0);
			printf("mini->pipe : %d\n", mini->pipe);
			mini->pipe--;
			pipe_execve(mini);
		}
		exit(0);
	}
	else if (pid > 0)
	{
		pid2 = fork();
		pipe(p_fd);
		if (pid2 == 0)
		{
			dup2(p_fd[1], fd[1]);
			execve(cmd);
		}
		else if (pid2 > 0)
			wait();
		wait(&status);
		printf("parent : mini->pipe : %d\n", mini->pipe);
	}
	else if (pid == -1)
		printf("minishell: %s\n", strerror(errno));
}
