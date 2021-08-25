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
	mini->first = 0;
	mini->err.malloc = -1;
	mini->err.cmd = -2;
	mini->err.quo = -3;
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
		return (mini->err.malloc);
	i = -1;
	while (str[++i] == ' ')
		;
	if (str[i] == 0)
		return (-2);
	ret = space_split(&str[i], ' ', mini); //주어진 문자열을 공백기준으로 쪼갬
	if (ret == mini->err.malloc) //누수검사 필요
		return (cmd_err("daekim zzang", mini->err.malloc, mini));
	if (mini->odd_quo == 1)
		return (cmd_err("doyun ZZANG", mini->err.quo, mini));
	while (*(mini->buf[mini->first]) == 0)//
	{
		mini->first++;
		if (mini->buf[mini->first] == 0)
			return (0);
	}
	cmd_ret = check_cmd(mini->buf[mini->first], mini, mini->envp);
	if (cmd_ret == mini->err.cmd)
		return (cmd_err(mini->buf[mini->first], mini->err.cmd, mini));
	if (cmd_ret == mini->err.malloc)
		return (cmd_err(mini->buf[mini->first], mini->err.malloc, mini));
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
		if (ret == mini.err.malloc) //문자열 파싱구분
			return (mini.err.malloc);
		add_history(str);
		if (ret == mini.err.cmd)
		{
			ft_free(mini.path);
			ft_free(mini.buf);
			free(str);
			continue ;
		}
		ft_free(mini.path);
		ft_free(mini.buf);	
		free(str);
	}
	return (0);
}
