#include "minishell.h"

void	mini_init(t_mini *mini) //mini구조체 안 single,double quo의 초기화 역슬래쉬와 인용구의 갯수도 체크
{
	mini->s_quo = 0;
	mini->d_quo = 0;
	mini->cnt_rvslash = 0;
	mini->cnt_quo = 0;
	mini->odd_quo = 0;
}

int	parsing(char *str, t_mini *mini)
{
	int ret;
	int cmd_ret;

	// 최초 공백 무시 필요
	mini_init(mini);
	ret = space_split(str, ' ', mini); //주어진 문자열을 공백기준으로 쪼갬
	if (ret == -1) //누수검사 필요
		return (-1);
	cmd_ret = check_cmd(mini->buf[0]);
	if (cmd_ret == -2)
		return (cmd_err(mini->buf[0]));
	if (mini->odd_quo == 1)
		return (print_err("odd quo"));
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
		ret = parsing(str, &mini);
		if (ret == -1) //문자열 파싱구분
			return (-1);
		add_history(str);
		if (ret == -2)
		{
			free(str);
			continue ;
		}
		i = -1;
		while (mini.buf[++i])
			printf("%s\n", mini.buf[i]);
		free(str);
	}
	return (0);
}
