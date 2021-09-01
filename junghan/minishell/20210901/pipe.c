#include "minishell.h"

void	oper_pipe(t_mini *mini, t_pipe *pi)
{
	if (ft_strchr(pi->temp[0], '/') != 0)
	{
		if (execve(pi->temp[0], pi->temp, *mini->envp) == -1)
		{
			cmd_err(pi->temp[0], mini->err.cmd, mini);
			exit(1);
		}
	}
	else
	{
		pi->jdx = -1;
		while (mini->path[++(pi->jdx)])
		{
			pi->cmd = ft_strjoin(mini->path[pi->jdx], mini->buf[pi->idx]);
			if (pi->cmd == NULL)
			{
				cmd_err(pi->temp[0], mini->err.malloc, mini);
				exit(1);
			}
			execve(pi->cmd, pi->temp, 0);
		}
		cmd_err(pi->temp[0], mini->err.cmd, mini);
	}
	exit(0);
}

int	fork_pipe(t_mini *mini, t_pipe *pi)
{
	pi->pid = fork();
	if (pi->pid == 0)
	{
		if (pi->initial != mini->pipe)
		{
			dup2(pi->fd[0], 0);
			close(pi->fd[0]);
			close(pi->fd[1]);
		}
		if (mini->pipe != 0)
			dup2(pi->fd2[1], 1);
		oper_pipe(mini, pi);
	}
	else if (pi->pid > 0)
	{
		waitpid(pi->pid, &(pi->status), 0);
		pipe(pi->fd);
		dup2(pi->fd2[0], pi->fd[0]);
		close(pi->fd2[0]);
		close(pi->fd2[1]);
		pipe(pi->fd2);
	}
	if (pi->status)
		return (mini->err.malloc);
	return (0);
}

int	parsing_pipe(t_mini *mini, t_pipe *pi)
{
	pi->idx = pi->count + 1;
	while (mini->buf[++(pi->count)])
		if (ft_strncmp(mini->buf[pi->count], "|", 2) == 0)
			break ;
	pi->temp = (char **)ft_calloc(pi->count + 1, sizeof(char *));
	if (pi->temp == 0)
		return (mini->err.malloc);
	pi->jdx = -1;
	while (mini->buf[pi->idx + ++(pi->jdx)] && \
			ft_strncmp(mini->buf[pi->idx + pi->jdx], "|", 2))
	{
		pi->temp[pi->jdx] = ft_strdup(mini->buf[pi->idx + pi->jdx]);
		if (pi->temp[pi->jdx] == 0)
		{
			ft_free(pi->temp);
			return (mini->err.malloc);
		}
	}
	return (0);
}

int	pipe_execve(t_mini *mini, t_pipe *pi)
{
	int		ret;

	pi->initial = mini->pipe++;
	pipe(pi->fd);
	pipe(pi->fd2);
	pi->idx = -1;
	pi->count = -1;
	while (mini->pipe--)
	{
		ret = parsing_pipe(mini, pi);
		if (ret)
			return (ret);
		ret = fork_pipe(mini, pi);
		if (ret)
			return (ret);
		ft_free(pi->temp);
	}
	return (0);
}
