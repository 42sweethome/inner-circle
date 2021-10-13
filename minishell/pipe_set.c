#include "minishell.h"

void	oper_pipe(t_mini *mini, t_pipe *pi)
{
	if (ft_strchr(pi->temp[0], '/') != 0)
	{
		if (execve(pi->temp[0], pi->temp, mini->envp) == -1)
			exit(127);
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
	}
	exit(127);
}

void	connect_pipe(t_mini *mini, t_pipe *pi)
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
}

int	fork_pipe(t_mini *mini, t_pipe *pi)
{
	pi->pid[pi->pid_idx] = fork();
	if (pi->pid[pi->pid_idx] == 0)
	{
		connect_pipe(mini, pi);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (mini->redirect)
			redirect_fd(mini->red[pi->pid_idx], mini->red_cnt[pi->pid_idx], \
			pi->pid_idx);
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

void	cmd_offset(t_mini *mini, int *i)
{
	while (mini->buf[(*i)++])
	{
		if (ft_strncmp(mini->buf[*i], "|", 2) == 0)
		{	
			(*i)++;
			break ;
		}
	}
}
