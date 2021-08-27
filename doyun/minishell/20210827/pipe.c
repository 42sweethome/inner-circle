#include "minishell.h"

int	connect_pipe(int *fd, int inout, t_mini *mini)
{
	if (dup2(fd[inout],inout) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (mini->err.pipe);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}

int	run_cmd(t_mini *mini, int pipe)
{
	char	*test1[3] = {"/bin/cat", "a.c", NULL};
	char	*test2[3] = {"/bin/cat", "b.c", NULL};
	char	*test3[3] = {"/usr/bin/grep", "a", NULL};


	if (pipe == 2)
	{
		if (execve(test1[0], test1, *mini->envp) == -1)
			printf("p_error %d 1\n", pipe);
	}
	if (pipe == 1)
	{
		if (execve(test2[0], test2, *mini->envp) == -1)
			printf("p_error %d 2\n", pipe);
	}
	if (pipe == 0)
	{
		if (execve(test3[0], test3, *mini->envp) == -1)
			printf("p_error %d 3\n", pipe);
	}
	printf("trying %d \n", pipe);
	write(1, "d3\n", 3);
	return (0);
}

int	cmd_in_pipe(t_mini *mini, int cmd_num, int *prev_fd)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	char	*test1[3] = {"/bin/cat", "a.c", NULL};
	char	*test2[3] = {"/bin/cat", "b.c", NULL};
	char	*test3[3] = {"/usr/bin/grep", "a", NULL};

//	if (pipe(fd) == -1)
//		return (mini->err.pipe);
	char buf[1024];
	printf("gggg%d\n", cmd_num);
	write(1, "dd\n", 3);
	if (cmd_num == 0)
	{
		connect_pipe(prev_fd, 1, mini);
		if (run_cmd(mini, cmd_num) == -1)
			return (mini->err.pipe);	
	}
	pipe(fd);
	pid = fork();
	if (pid == -1)
		return (mini->err.pipe);
	else if (pid == 0)
		cmd_in_pipe(mini, cmd_num - 1, prev_fd);
	if (waitpid(pid, &status, WNOHANG) == -1)
		return (mini->err.pipe);
	connect_pipe(prev_fd, 1, mini);
	connect_pipe(fd, 0, mini);
	if (cmd_num == 2)
	{
		if (execve(test1[0], test1, *mini->envp) == -1)
			printf("p_error %d 1\n", mini->pipe);
	}
	if (cmd_num == 1)
	{
		if (execve(test2[0], test2, *mini->envp) == -1)
			printf("p_error %d 2\n", mini->pipe);
	}
	if (cmd_num == 0)
	{
		if (execve(test3[0], test3, *mini->envp) == -1)
			printf("p_error %d 3\n", mini->pipe);
	}
	return (0);
}


int	pipe_execve(t_mini *mini)
{
	int	fd[2];
	int	status;
	pid_t	pid;
	mini->pipe += 1; 

	if (pipe(fd) == -1)
		return (mini->err.pipe);
//	pipe(fd);
	pid = fork();
	if (pid == -1)
		return (mini->err.pipe);
	else if (pid == 0)
		cmd_in_pipe(mini, mini->pipe - 1, fd);
	if (waitpid(pid, &status, WNOHANG) == -1)
		return (mini->err.pipe);
	connect_pipe(fd, 0, mini);
	if (run_cmd(mini, mini->pipe) == mini->err.pipe)
		return (mini->err.pipe);
	return (0);
}
