#include "minishell.h"

void    redirect_stdout(char *file)
{
    int     fd;

    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    dup2(fd, 1); 
    close(fd);
}

void    redirect_append(char *file)
{
    int     fd;

    fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
    dup2(fd, 1);
    close(fd);
}

void    redirect_stdin(char *file)
{
    int     fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit(errno);
    dup2(fd, 0);
    close(fd);
}

void    redirect_heredoc(char *file)
{
    int     fd;

    fd = open(file, O_RDONLY);
    dup2(fd, 0);
    close(fd);
}

void    redirect_fd(t_redir *red, int cnt, int idx)
{
    int     i;

    i = -1;
    while (++i < cnt)
    {
        if (!ft_strncmp(red[i].redir, ">", 2))
            redirect_stdout(red[i].file);
        else if (!ft_strncmp(red[i].redir, ">>", 3))
            redirect_append(red[i].file);
        else if (!ft_strncmp(red[i].redir, "<", 2))
            redirect_stdin(red[i].file);
        else if (!ft_strncmp(red[i].redir, "<<", 3))
            redirect_heredoc(ft_strjoin("/tmp/.", ft_itoa(idx)));
    }
}