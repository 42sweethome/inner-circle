#include "minishell.h"

int	mini_init(t_mini *mini)
{
	mini->red = 0;
	mini->pipe = 0;
	mini->first = 0;
	mini->upper = 0;
	mini->s_quo = 0;
	mini->d_quo = 0;
	mini->cnt_quo = 0;
	mini->odd_quo = 0;
	mini->option_n = 0;
	mini->redirect = 0;
	mini->err.malloc = -1;
	mini->err.cmd = -2;
	mini->err.quo = -3;
	mini->err.path_malloc = -4;
	mini->err.only_space = -5;
	mini->err.pipe = -6;
	mini->err.redirect = -7;
	if (get_path(mini) == mini->err.malloc)
		return (mini->err.malloc);
	return (0);
}

void	pipe_init(t_mini *mini, t_pipe *pi)
{
	pi->initial = mini->pipe++;
	pi->pid = (int *)ft_calloc(mini->pipe, sizeof(int));
	pi->fd = (int **)ft_calloc(pi->initial, sizeof(int *));
	pi->pid_idx = -1;
	while (++(pi->pid_idx) < pi->initial)
		pi->fd[pi->pid_idx] = (int *)ft_calloc(2, sizeof(int));
	pi->pid_idx = 0;
	pi->idx = -1;
	pi->count = -1;
}

void	init_env(char ***env, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		;
	*env = (char **)ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (envp[++i])
		(*env)[i] = ft_strdup(envp[i]);
}

void	ori_term_init(t_mini mini)
{
	tcgetattr(0, &mini.ori_term);
}

void	mini_term_init(t_mini mini)
{
	tcgetattr(0, &mini.mini_term);
	mini.mini_term.c_lflag &= ~(ECHOCTL);
	mini.mini_term.c_cc[VMIN] = 1;
	mini.mini_term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &mini.mini_term);
}
