#include "minishell.h"

void	redir_realloc(t_mini *mini, int cnt)
{
	int		idx;
	int		jdx;
	char	**tmp;

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

int	get_red_info(t_mini *mini, int pipe_idx, int *redir_idx, int *idx)
{
	mini->red[pipe_idx][*redir_idx].redir = ft_strdup(mini->buf[*idx]);
	mini->red[pipe_idx][(*redir_idx)++].file = ft_strdup(mini->buf[++(*idx)]);
	if (!mini->buf[*idx] || \
	*(mini->buf[*idx]) == '|' || *(mini->buf[*idx]) == '\0' || \
	*(mini->buf[*idx]) == '<' || *(mini->buf[*idx]) == '>')
	{
		if (!mini->buf[*idx])
			cmd_err(mini->buf[*idx - 1], mini->err.redirect, mini);
		else
			cmd_err(mini->buf[*idx], mini->err.redirect, mini);
		return (-1);
	}
	return (0);
}

int	redir_init(t_mini *mini)
{
	int		idx;
	int		redir_idx;
	int		pipe_idx;
	int		cnt;

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
			if (get_red_info(mini, pipe_idx, &redir_idx, &idx) == -1)
				return (-1);
		}
		else
			cnt++;
	}
	return (cnt);
}
