#include "minishell.h"

void    ori_term_init(t_mini mini)
{
    tcgetattr(0, &mini.ori_term);
}

void    mini_term_init(t_mini mini)
{
    tcgetattr(0, &mini.mini_term);
    mini.mini_term.c_lflag &= ~(ECHOCTL);
    mini.mini_term.c_cc[VMIN] = 1;               // 1 바이트씩 처리
    mini.mini_term.c_cc[VTIME] = 0;   
    tcsetattr(0, TCSANOW, &mini.mini_term);
}