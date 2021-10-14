#include "minishell.h"

void	sig_handler(int	signum)
{
	if (signum)
	{
		printf("\n");
		rl_on_new_line();
	//	rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_ctrl_d(void)
{
	printf("exit\n");
	exit(0);
}
