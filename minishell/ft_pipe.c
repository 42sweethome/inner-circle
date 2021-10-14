#include "minishell.h"

int	pipe_wait(t_mini *mini, t_pipe *pi)
{
	int	i;
	int	j;
	int	ret;
	int	status;

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

	pipe_init(mini, pi);
	ret = 0;
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
