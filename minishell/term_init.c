#include "minishell.h"

void    ori_term_init(t_mini mini)
{
    tcgetattr(0, &mini.ori_term);
}

void    mini_term_init(t_mini mini)
{
    tcgetattr(0, &mini.mini_term);
    mini.mini_term.c_lflag &= ~ECHOCTL;
    tcsetattr(0, TCSANOW, &mini.mini_term);
}