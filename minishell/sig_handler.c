#include "minishell.h"

void	sig_handler(int	signum)
{
	if (signum)
	{
		printf("\n"); //prompt간 줄 바꿈
		rl_on_new_line(); //출력된 문자열 다음의 new prompt line으로 이동
		rl_replace_line("",0); //이전에 사용한 buffer를 비워줌
		rl_redisplay(); //비워진 새 newline을 출력
	}
}

void	sig_ctrl_d(void)
{
	printf("exit\n");
	exit(0); //???? 0인지 확실 x
}