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
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (mini->redirect)
			redirect_fd(mini->red[pi->pid_idx], mini->red_cnt[pi->pid_idx], pi->pid_idx);
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

int	case_of_status(t_mini *mini, char *cmd, int status)
{
	mini->exit_stat = WEXITSTATUS(status);
	if (status == 3072)
		return (mini->err.malloc);
	else if (status == 2)
		printf("^C\n");
	else if (status == 3)
		printf("^\\");
	else if (WEXITSTATUS(status) == 2) //????
		printf("minishell: %s\n", strerror(WEXITSTATUS(status)));
	else if (WEXITSTATUS(status) == 127) //????
		cmd_err(cmd, mini->err.cmd, mini);
	return (1);
}

void cmd_offset(t_mini *mini, int *j)
{
	while (mini->buf[(*j)++])
	{
		if (ft_strncmp(mini->buf[*j], "|", 2) == 0)
		{	
			(*j)++;
			break ;
		}
	}
}

int pipe_wait(t_mini *mini, t_pipe *pi)
{
	int i;
	int j;
	int ret;
	int status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	i = -1;
	j = 0;
	while (++i <= pi->initial)
	{
		waitpid(pi->pid[i], &status, 0);
		ret = case_of_status(mini, mini->buf[j], status);
		if (ret == 0)
			return (0);
		else if (ret == mini->err.malloc)
			return (mini->err.malloc);
		cmd_offset(mini, &j);
	}
	return (0);
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
	ret = 0;
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
	ret = pipe_wait(mini, pi);
	mini->pipe = pi->initial;
	ft_int_free(pi->fd, pi->initial, pi->pid);
	return (ret);
}
