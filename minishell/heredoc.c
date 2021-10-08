#include "minishell.h"

void    make_tmp(char *delimeter, int idx)
{
    int     fd;
    char    *tmp;
    char    *line;

    tmp = ft_strjoin("/tmp/.", ft_itoa(idx));
    fd = open(tmp, O_RDWR | O_CREAT, 0666);
    while(1)
    {
        signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);// SIG_ING 시그널 무시
        line = readline("> ");
        if (!line)
			break; // ????
        if (!ft_strncmp(line, delimeter, ft_strlen(delimeter) + 1))
        {
            close(fd);
            break;
        }
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
    }
}

void    tmp_heredoc(t_mini *mini)
{
    int     idx;
    int     jdx;

    idx = -1;
    while (++idx < mini->pipe + 1)
    {
        jdx = -1;
        while (++jdx <mini->red_cnt[idx])
        {
            if (!ft_strncmp(mini->red[idx][jdx].redir, "<<", 3))
                make_tmp(mini->red[idx][jdx].file, idx);
        }
    }
}