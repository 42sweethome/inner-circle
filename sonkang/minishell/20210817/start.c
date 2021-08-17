#include "minishell.h"

void	mini_init(t_mini *mini) //mini구조체 안 single,double quo의 초기화 역슬래쉬와 인용구의 갯수도 체크
{
	mini->s_quo = 0;
	mini->d_quo = 0;
	mini->cnt_rvslash = 0;
	mini->cnt_quo = 0;
	mini->odd_quo = 0;
	mini->err.malloc = -1;
	mini->err.cmd = -2;
	mini->err.quo = -3;
}

int	parsing(char *str, t_mini *mini)
{
	int ret;
	int cmd_ret;
	int	i;

	// 최초 공백 무시 필요
	mini_init(mini);
	i = -1;
	while (str[++i] == ' ')
		;
	if (str[i] == 0)
		return (-2);
	ret = space_split(&str[i], ' ', mini); //주어진 문자열을 공백기준으로 쪼갬
	if (ret == mini->err.malloc) //누수검사 필요
		return (cmd_err("daekim zzang", mini->err.malloc, mini));
	if (mini->odd_quo == 1)
		return (cmd_err("ZZang", mini->err.quo, mini));
	cmd_ret = check_cmd(mini->buf[0], mini);
	if (cmd_ret == mini->err.cmd)
		return (cmd_err(mini->buf[0], mini->err.cmd, mini));
	return (0);
}

int	main() //파싱작업
{
	char	*str;
	t_mini	mini;
	int	i;
	int	ret;

	while (1)
	{
 		str = readline("minishell $ "); //표준입력
		if (*str == 0)
			continue ;
		ret = parsing(str, &mini);
		if (ret == mini.err.malloc) //문자열 파싱구분
			return (mini.err.malloc);
		add_history(str);
		if (ret == mini.err.cmd)
		{
			free(str);
			continue ;
		}
		i = -1;
		while (mini.buf[++i])
			printf("%s\n", mini.buf[i]);
		ft_free(mini.buf);	
		free(str);
	}
	return (0);
}
