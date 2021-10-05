#include "minishell.h"

void	oper_pipe(t_mini *mini, t_pipe *pi)
{
	if (ft_strchr(pi->temp[0], '/') != 0)
	{
		if (execve(pi->temp[0], pi->temp, *mini->envp) == -1)
		{
			//cmd_err(pi->temp[0], mini->err.cmd, mini);
			exit(errno);
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
				exit(mini->err.malloc);
			}
			execve(pi->cmd, pi->temp, 0);
		}
		//cmd_err(pi->temp[0], mini->err.cmd, mini);
	}
	exit(errno);
}

int	fork_pipe(t_mini *mini, t_pipe *pi)
{
	pi->pid[pi->pid_idx] = fork();
	if (pi->pid[pi->pid_idx] == 0)
	{
		if (pi->initial != mini->pipe)
		{
			dup2(pi->fd[pi->pid_idx - 1][0], 0);
			close(pi->fd[pi->pid_idx - 1][0]);
			close(pi->fd[pi->pid_idx - 1][1]);
		}
		if (mini->pipe != 0)
		{
			dup2(pi->fd[pi->pid_idx][1], 1);
			close(pi->fd[pi->pid_idx][0]);
			close(pi->fd[pi->pid_idx][1]);
		}
		oper_pipe(mini, pi);
	}
	else if (pi->pid_idx > 0)
	{
		close(pi->fd[pi->pid_idx - 1][0]);
		close(pi->fd[pi->pid_idx - 1][1]);
	}
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

void pipe_wait(t_pipe *pi)
{
	int i;
	int status;

	i = -1;
	while (++i <= pi->initial)
		waitpid(pi->pid[i], &status, 0);
}

int	pipe_execve(t_mini *mini, t_pipe *pi)
{
	int		ret;

	pi->initial = mini->pipe++;
	pi->pid = (int *)ft_calloc(mini->pipe, sizeof(int));
	pi->fd = (int **)ft_calloc(pi->initial, sizeof(int *));
	pi->pid_idx = -1;
	while (++(pi->pid_idx) < pi->initial)
		pi->fd[pi->pid_idx] = (int *)ft_calloc(2, sizeof(int));
	pi->pid_idx = 0;
	pi->idx = -1;
	pi->count = -1;
	while (mini->pipe--)
	{
		if (mini->pipe > 0)
			pipe(pi->fd[pi->pid_idx]);
		ret = parsing_pipe(mini, pi);
		if (ret)
			return (ret);
		ret = fork_pipe(mini, pi);
		if (ret)
			return (ret);
		ft_free(pi->temp);
		pi->pid_idx++;
	}
	pipe_wait(pi);
	mini->pipe = 1;
	return (0);
}