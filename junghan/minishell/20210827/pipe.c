#include "minishell.h"

int	pipe_execve(t_mini *mini)
{
	int pid;
	int status;
	int fd[2];
	int fd2[2];
	char	*test1[3] = {"/bin/cat", "a.c", NULL};
	char	*test3[3] = {"/bin/cat", "b.c", NULL};
	char	*test4[3] = {"/usr/bin/grep", "a", NULL};//{"/bin/cat", "c.c", NULL};
	char	*test2[3] = {"/usr/bin/grep", "a", NULL};
	int initial;
//	char buf[1024];

	initial = mini->pipe++;
	pipe(fd);
	pipe(fd2);
	while (mini->pipe--)
	{
		pid = fork();
		if (pid == 0)
		{
			if (initial != mini->pipe)
			{
				dup2(fd[0], 0);
				close(fd[0]);
				close(fd[1]);
			}
			if (mini->pipe != 0)
			{
				dup2(fd2[1], 1);
				//close(fd2[1]);
			}
			if (mini->pipe == 3)
			{
				if (execve(test1[0], test1, *mini->envp) == -1)
					printf("p_error %d 4\n", mini->pipe);
			}
			if (mini->pipe == 2)
			{
				if (execve(test3[0], test3, *mini->envp) == -1)
					printf("p_error %d 1\n", mini->pipe);
			}
			if (mini->pipe == 1)
			{
				if (execve(test4[0], test4, *mini->envp) == -1)
					printf("p_error %d 3\n", mini->pipe);
			}
			if (mini->pipe == 0)
			{	
				if (execve(test2[0], test2, 0) < 0)
					printf("p_error %d 2\n", mini->pipe);
			}
			exit(0);
		}
		else if (pid > 0)
		{
			printf("p_pid %d pipe %d\n", pid, mini->pipe);
			waitpid(pid, &status, 0);
			pipe(fd);
			dup2(fd2[0], fd[0]);
			close(fd2[0]);
			close(fd2[1]);
			pipe(fd2);
		}
	}
	return (mini->err.pipe);
}



/*
int	pipe_execve(t_mini *mini)
{
	int pid;
	int status;
	int fd[2];
	int fd2[2];
	char	*test1[3] = {"/bin/cat", "a.c", NULL};
	char	*test3[3] = {"/bin/cat", "b.c", NULL};
	char	*test4[3] = {"/usr/bin/grep", "a", NULL};//{"/bin/cat", "c.c", NULL};
	char	*test2[3] = {"/usr/bin/grep", "a", NULL};
	int initial;
//	char buf[1024];

	initial = mini->pipe++;
	pipe(fd);
	pipe(fd2);
	while (mini->pipe--)
	{
		pid = fork();
		if (pid == 0)
		{
			if (initial != mini->pipe)
			{
				dup2(fd[0], 0);
				close(fd[0]);
				close(fd[1]);
			}
			if (mini->pipe != 0)
			{
				dup2(fd2[1], 1);
				//close(fd2[1]);
			}
			if (mini->pipe == 3)
			{
				if (execve(test1[0], test1, *mini->envp) == -1)
					printf("p_error %d 4\n", mini->pipe);
			}
			if (mini->pipe == 2)
			{
				if (execve(test3[0], test3, *mini->envp) == -1)
					printf("p_error %d 1\n", mini->pipe);
			}
			if (mini->pipe == 1)
			{
				if (execve(test4[0], test4, *mini->envp) == -1)
					printf("p_error %d 3\n", mini->pipe);
			}
			if (mini->pipe == 0)
			{	
				if (execve(test2[0], test2, 0) < 0)
					printf("p_error %d 2\n", mini->pipe);
			}
			exit(0);
		}
		else if (pid > 0)
		{
			printf("p_pid %d pipe %d\n", pid, mini->pipe);
			waitpid(pid, &status, 0);
			pipe(fd);
			dup2(fd2[0], fd[0]);
			close(fd2[0]);
			close(fd2[1]);
			pipe(fd2);
	//		printf("stat %d\n", status);
		}
	}
	return (mini->err.pipe);
}



*/
