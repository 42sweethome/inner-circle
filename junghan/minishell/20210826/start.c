#include "minishell.h"

int	get_path(t_mini *mini)
{
	char		*path;
	char		*temp;
	int			idx;
//	static int	path_flag;

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

int	mini_init(t_mini *mini) //mini구조체 안 single,double quo의 초기화 역슬래쉬와 인용구의 갯수도 체크
{
	mini->s_quo = 0;
	mini->d_quo = 0;
	mini->cnt_rvslash = 0;
	mini->cnt_quo = 0;
	mini->odd_quo = 0;
	mini->pipe = 0;
	mini->first = 0;
	mini->err.malloc = -1;
	mini->err.cmd = -2;
	mini->err.quo = -3;
	mini->err.path_malloc = -4;
	mini->err.split_malloc = -5;
	mini->err.only_space = -6;
	mini->err.pipe = -7;
	if (get_path(mini) == mini->err.malloc)
		return (mini->err.malloc);
	return (0);
}

int	parsing(char *str, t_mini *mini)
{
	int ret;
	int cmd_ret;
	int	i;

	// 최초 공백 무시 필요
	if (mini_init(mini) == mini->err.malloc)
		return (cmd_err("path error", mini->err.path_malloc, mini));
	i = -1;
	while (str[++i] == ' ')
		;
	if (str[i] == 0)
		return (mini->err.only_space);
	ret = space_split(&str[i], ' ', mini); //주어진 문자열을 공백기준으로 쪼갬
	if (ret == mini->err.malloc) //누수검사 필요
		return (cmd_err("daekim zzang", mini->err.malloc, mini));
	else if (ret == mini->err.split_malloc)
		return (cmd_err("daekim zzang", mini->err.split_malloc, mini));
	else if (ret == mini->err.pipe)
		return (cmd_err("daekim zzang", mini->err.pipe, mini));
	if (mini->odd_quo == 1)
		return (cmd_err("doyun ZZANG", mini->err.quo, mini));
	while (*(mini->buf[mini->first]) == 0)//
	{
		mini->first++;
		if (mini->buf[mini->first] == 0)
			return (0);
	}
	if (pipe_execve(mini) == mini->err.pipe)
		return (cmd_err("daekim zzang", mini->err.pipe, mini));
	cmd_ret = check_cmd(mini->buf[mini->first], mini, mini->envp);
	if (cmd_ret == mini->err.cmd)
		return (cmd_err(mini->buf[mini->first], mini->err.cmd, mini));
	if (cmd_ret == mini->err.malloc)
		return (cmd_err(mini->buf[mini->first], mini->err.malloc, mini));
	return (0);
}

int	main_free(t_mini *mini, char *str, int ret)
{
	if (ret == mini->err.path_malloc || ret == mini->err.split_malloc || \
			ret == mini->err.only_space)
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
	while (1)
	{
		str = readline("minishell $ "); //표준입력
		if (str == 0 || *str == 0)
			continue ;
		mini.envp = &envp;
		ret = parsing(str, &mini);
		add_history(str);
		ret = main_free(&mini, str, ret);
		if (ret == mini.err.cmd)
			continue ;
		else if (ret == mini.err.path_malloc || ret == mini.err.split_malloc)
			return (mini.err.malloc);
	}
	return (0);
}
