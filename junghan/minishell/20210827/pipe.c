#include "minishell.h"

int	pipe_execve(t_mini *mini)
{
	int		pid;
	int		com_idx;
	int		status;
	int		fd[2];

	char	*test1[3] = {"/bin/cat", "a.c", NULL};
	char	*test3[3] = {"/bin/cat", "b.c", NULL};
	char	*test2[3] = {"/usr/bin/grep", "a", NULL};
;
	//char	*str;

	pipe(fd);
	int initial;
//	char 	buf[1024];
	initial = mini->pipe++;
	com_idx = 0;
	while (mini->pipe--)
	{
		pid = fork();
		if (pid == 0)
		{
			if (initial != mini->pipe)
			{
				//close(fd[0])
				dup2(fd[0], 0);
				close(fd[0]);
			//	close(fd[1]);
			//	read(fd[0], buf, 3);
			//	buf[2] = '\0';
				//printf("buf : %s mini->pipe : %d\n", buf, mini->pipe);
			}
			if (mini->pipe != 0)
			{
				dup2(fd[1], 1);
				close(fd[1]);
				close(fd[0]);
			}
			//close(0);
			//printf("??\n");
			//str = strdup("grep c");
			//execve(mini->buf[com_idx], mini->buf, *mini->envp);
			//printf("pipe %d 1\n", mini->pipe);*/
			if (mini->pipe == 2)
			{
				if (execve(test1[0], test1, *mini->envp) == -1)
					printf("p_error %d 1\n", mini->pipe);
			}
			if (mini->pipe == 1)
			{
				if (execve(test3[0], test3, *mini->envp) == -1)
					printf("p_error %d 3\n", mini->pipe);
			}
			//printf("pipe %d 2\n", mini->pipe);
			if (mini->pipe == 0)
			{
				if (execve(test2[0], test2, *mini->envp) == -1)
					printf("p_error %d 2\n", mini->pipe);
				else
					exit(0);
				printf("???\n");
			}
			//printf("%d")
			exit(0);

		}
		else if (pid > 0)
		{
			printf("p_pid %d \n", pid);
			if (mini->pipe == 0)
			{
				close(fd[0]);
				close(fd[1]);
			}
			//wait(&status);
			//if (mini->pipe > 0)
			waitpid(pid, &status, 0);
			printf("stat %d\n", status);
		}
	}
	return (mini->err.pipe);
}
