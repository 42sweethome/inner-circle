#include "minishell.h"

int	get_path(t_mini *mini)
{
	char		*path;
	char		*temp;
	int			idx;
	int			ret;

	ret = ft_getenv(mini, &path, "PATH");
	if (ret == mini->err.malloc)
		return (mini->err.malloc);
	if (ret == 0)
	{
		mini->path = (char **)ft_calloc(1, sizeof(char*));
		mini->path[0] = 0;
		return (1);
	}
	mini->path = ft_split(path, ':');
	idx = -1;
	while (mini->path[++idx])
	{
		temp = ft_strjoin(mini->path[idx], "/");
		if (temp == NULL)
		{
			ft_free(mini->path);
			free(path);
			return (mini->err.malloc);
		}
		free(mini->path[idx]);
		mini->path[idx] = temp;
	}
	free(path);
	return (0);
}

int	mini_init(t_mini *mini) //mini구조체 안 single,double quo의 초기화 역슬래쉬와 인용구의 갯수도 체크
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

int	func_cmd(t_mini *mini)
{
	int cmd_ret;

	cmd_ret = check_cmd(mini->buf[mini->first], mini, &mini->envp);
	if (cmd_ret == mini->err.malloc)
		return (cmd_err(mini->buf[mini->first], mini->err.malloc, mini));
	return (1);
}

int	func_pipe(t_mini *mini)
{
	int pipe_ret;

	pipe_ret = 0;
	if (mini->pipe)
		pipe_ret = pipe_execve(mini, &(mini->pipe_struct));
	if (mini->pipe && pipe_ret == 0)
		return (0);
	else if (pipe_ret == mini->err.malloc)
		return (cmd_err("malloc error", mini->err.malloc, mini));
	return (1);
}

int	func_split(t_mini *mini, char *str)
{
	int ret;

	ret = space_split(str, ' ', mini); //주어진 문자열을 공백기준으로 쪼갬
	if (ret == mini->err.malloc) //누수검사 필요
		return (cmd_err("alloc error", mini->err.malloc, mini));
	else if (ret == mini->err.pipe)
		return (cmd_err("pipe error", mini->err.pipe, mini));
	else if (ret == mini->err.redirect)
		return (-2);
	if (mini->odd_quo == 1)
		return (cmd_err("odd_quo", mini->err.quo, mini));
	return (1);
}

int	mini_process(char *str, t_mini *mini)
{
	int ret;
	int	i;

	// 최초 공백 무시 필요
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

int	main_free(t_mini *mini, char *str, int ret)
{
	if (mini->redirect)
	{
		ft_struct_free(mini, mini->red);
		free(mini->red_cnt);
	}
	if (ret == mini->err.path_malloc || ret == mini->err.only_space)
	{
		ft_free(mini->path);
		free(str);
		return (mini->err.malloc);
	}
	else if (ret == mini->err.malloc)
	{
		ft_free(mini->path);
		ft_free(mini->buf);
		free(str);
		return (mini->err.malloc);
	}
	else if (ret == mini->err.cmd)
	{
		ft_free(mini->path);
		ft_free(mini->buf);
		free(str);
		return (mini->err.cmd);
	}
	ft_free(mini->path);
	ft_free(mini->buf);	
	free(str);
	return (0);
}

void init_env(char ***env, char **envp)
{
	int i;
	
	i = -1;
	while (envp[++i])
		;
	*env = (char **)ft_calloc(i + 1, sizeof(char *));	
	i = -1;
	while (envp[++i])
		(*env)[i] = ft_strdup(envp[i]);
}

int	main(int argc, char **argv, char **envp) //파싱작업
{
	char	*str;
	t_mini	mini;
	int	ret;

	if (argc != 1 || argv[1] != 0)
	{
		mini.err.argv = -4;
		cmd_err(argv[1], mini.err.argv, &mini);
		return (0);
	}
	mini.exit_stat = 0;
	init_env(&mini.envp, envp);
	ori_term_init(mini);
	while (1)
	{
		mini_term_init(mini);
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, SIG_IGN);
		str = readline("minishell $ "); //표준입력
		if (!str)
			sig_ctrl_d();
		if (str == 0 || *str == 0)
		{
			free(str);
			continue ;
		}
		ret = mini_process(str, &mini);
		rm_tmpfile(mini.pipe);
		add_history(str);
		ret = main_free(&mini, str, ret);
		if (ret == mini.err.cmd)
			continue ;
		else if (ret == mini.err.path_malloc)
			return (mini.err.malloc);
	}
	return (0);
}