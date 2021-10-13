#include "minishell.h"

int	func_split(t_mini *mini, char *str)
{
	int	ret;

	ret = space_split(str, ' ', mini);
	if (ret == mini->err.malloc)
		return (cmd_err("alloc error", mini->err.malloc, mini));
	else if (ret == mini->err.pipe)
		return (cmd_err("pipe error", mini->err.pipe, mini));
	else if (ret == mini->err.redirect)
		return (-2);
	if (mini->odd_quo == 1)
		return (cmd_err("odd_quo", mini->err.quo, mini));
	return (1);
}

int	func_redir(t_mini *mini)
{
	int	i;
	int	ret;

	if (!mini->redirect)
		return (1);
	mini->red = (t_redir **)ft_calloc(mini->pipe + 1, sizeof(t_redir *));
	i = -1;
	while (++i < mini->pipe + 1)
		mini->red[i] = (t_redir *)ft_calloc(mini->red_cnt[i], sizeof(t_redir));
	ret = redir_init(mini);
	if (ret == -1)
		return (mini->err.redirect);
	redir_realloc(mini, ret);
	tmp_heredoc(mini);
	return (1);
}

int	func_pipe(t_mini *mini)
{
	int	pipe_ret;

	pipe_ret = 0;
	if (mini->pipe)
		pipe_ret = pipe_execve(mini, &(mini->pipe_struct));
	if (mini->pipe && pipe_ret == 0)
		return (0);
	else if (pipe_ret == mini->err.malloc)
		return (cmd_err("malloc error", mini->err.malloc, mini));
	return (1);
}

int	func_cmd(t_mini *mini)
{
	int	cmd_ret;

	cmd_ret = check_cmd(mini->buf[mini->first], mini, &mini->envp);
	if (cmd_ret == mini->err.malloc)
		return (cmd_err(mini->buf[mini->first], mini->err.malloc, mini));
	return (1);
}

int	mini_process(char *str, t_mini *mini)
{
	int	ret;
	int	i;

	if (mini_init(mini) == mini->err.malloc)
		return (cmd_err("path error", mini->err.path_malloc, mini));
	i = -1;
	while (str[++i] == ' ')
		;
	if (str[i] == 0)
		return (mini->err.only_space);
	ret = func_split(mini, &str[i]);
	if (ret != 1)
		return (ret);
	ret = func_redir(mini);
	if (ret != 1)
		return (ret);
	ret = func_pipe(mini);
	if (ret != 1)
		return (ret);
	ret = func_cmd(mini);
	if (ret != 1)
		return (ret);
	return (0);
}
