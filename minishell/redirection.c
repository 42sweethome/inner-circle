#include "minishell.h"

void    redir_realloc(t_mini *mini, int cnt)
{
    int     idx;
    int     jdx;
    char    **tmp;

    tmp = (char **)ft_calloc(cnt + 1, sizeof(char *));
    idx = -1;
    jdx = 0;
    while (mini->buf[++idx])
    {
        if (*(mini->buf[idx]) == '<' || *(mini->buf[idx]) == '>')
            idx++;
        else
            tmp[jdx++] = ft_strdup(mini->buf[idx]);
        if (!mini->buf[idx])
            break ;
    }
    ft_free(mini->buf);
    mini->buf = tmp;
}

int    redir_init(t_mini *mini)
{
    int     idx;
    int     redir_idx;
    int     pipe_idx;
    int     cnt;

    idx = -1;
	pipe_idx = 0;
    redir_idx = 0;
    cnt = 0;
	while (mini->buf[++idx])
	{
		if (*(mini->buf[idx]) == '|')
        {
			pipe_idx++;
            redir_idx = 0;
        }
		if (*(mini->buf[idx]) == '<' || *(mini->buf[idx]) == '>')
		{
			mini->red[pipe_idx][redir_idx].redir = ft_strdup(mini->buf[idx]);
            mini->red[pipe_idx][redir_idx++].file = ft_strdup(mini->buf[++idx]);
            if (!mini->buf[idx] || *(mini->buf[idx]) == '|' || *(mini->buf[idx]) == '\0' \
                || *(mini->buf[idx]) == '<' || *(mini->buf[idx]) == '>')
                {
                    if (!mini->buf[idx])
                        cmd_err(mini->buf[idx - 1], mini->err.redirect, mini);
                    else
                        cmd_err(mini->buf[idx], mini->err.redirect, mini);
                    return (-1);
                }
		}
        else
            cnt++;
	}
    return (cnt);
}

int     func_redir(t_mini *mini)
{
    int     i;
    int     ret;

/*    i = -1;
    while (++i < mini->pipe)
    {
        if(mini->red_cnt[i])
            break;
    }
    if (i == mini->pipe && mini->red_cnt[i] == 0)
        return (1);*/
    if (!mini->redirect)
        return (1);
    mini->red = (t_redir **)ft_calloc(mini->pipe + 1, sizeof(t_redir *));
    i = -1;
    while (++i < mini->pipe + 1)
        mini->red[i] = (t_redir *)ft_calloc(mini->red_cnt[i], sizeof(t_redir));
    ret = redir_init(mini);
    if (ret == -1)
        return (mini->err.redirect);
    redir_realloc(mini, ret);
    tmp_heredoc(mini);
    return (1);
}