#include "minishell.h"

int	get_path(t_mini *mini)
{
	char	*path;
	char	*temp;
	int		idx;

	path = getenv("PATH");
	mini->path = ft_split(path, ':');
	idx = -1;
	while (mini->path[++idx])
	{
		temp = ft_strjoin(mini->path[idx], "/");
		if (temp == NULL)
		{
			ft_free(mini->path);
			return (mini->err.malloc);
		}
		free(mini->path[idx]);
		mini->path[idx] = temp;
	}
	return (0);
}

int	mini_init(t_mini *mini)
{
	mini->s_quo = 0;
	mini->d_quo = 0;
	mini->cnt_rvslash = 0;
	mini->cnt_quo = 0;
	mini->odd_quo = 0;
	mini->err.malloc = -1;
	mini->err.cmd = -2;
	mini->err.quo = -3;
	if (get_path(mini) == mini->err.malloc)
		return (mini->err.malloc);
	return (0);
}

int	parsing(char *str, t_mini *mini, char **envp)
{
	int ret;
	int cmd_ret;
	int	i;

	if (mini_init(mini) == mini->err.malloc)
		return (mini->err.malloc);
	i = -1;
	while (str[++i] == ' ')
		;
	if (str[i] == 0)
		return (-2);
	ret = space_split(&str[i], ' ', mini);
	if (ret == mini->err.malloc)
		return (cmd_err("cmd error", mini->err.malloc, mini));
	if (mini->odd_quo == 1)
		return (cmd_err("qou error", mini->err.quo, mini));
	cmd_ret = check_cmd(mini->buf[0], mini, envp);
	if (cmd_ret == mini->err.cmd)
		return (cmd_err(mini->buf[0], mini->err.cmd, mini));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	char	*str;
	int		ret;
	
	if (argc != 1 || argv[1] != 0)
	{
		mini.err.argv = -4;
		cmd_err(argv[1], mini.err.argv, &mini);
		return (0);
	}
	while (1)
	{
 		str = readline("minishell $ ");
		if (str == 0 || *str == 0)
			continue ;
		ret = parsing(str, &mini, envp);
		if (ret == mini.err.malloc)
			return (mini.err.malloc);
		add_history(str);
		if (ret == mini.err.cmd)
		{
			free(str);
			continue ;
		}
		ft_free(mini.buf);	
		free(str);
	}
	return (0);
}
