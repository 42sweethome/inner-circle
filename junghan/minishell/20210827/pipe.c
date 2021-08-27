#include "minishell.h"

int	pipe_execve(t_mini *mini)
{
	int		pid;
	int		status;
	int		fd[2];
	//char	*str;

	pipe(fd);
	/*	if (mini->pipe)
		{
		pid = fork();
		if (pid == 0)
		{
		dup2(fd[1], 1);
	//		str = strdup("ls");
	//	ft_execve(mini, mini->buf[0], mini->envp);
	printf("!!");
	exit(0);
	}
	else if (pid > 0)
	waitpid(pid, &status, 0);
	}
	 */
	int initial;
	char 	buf[1024];
	initial = mini->pipe++;
	while (mini->pipe--)
	{
		pid = fork();
		if (pid == 0)
		{
			if (initial != mini->pipe)
			{
				dup2(fd[0], 0);
				read(fd[0], buf, 3);
				buf[2] = '\0';
				printf("buf : %s mini->pipe : %d\n", buf, mini->pipe);
			}
			if (mini->pipe != 0)
				dup2(fd[1], 1);
			printf("??\n");
			//str = strdup("grep c");
			//execve(str, mini->buf, *mini->envp);
			exit(0);
		}
		else if (pid > 0)
			waitpid(pid, &status, 0);
	}
	return (mini->err.pipe);
}
