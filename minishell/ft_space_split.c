/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/10/14 18:23:04 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe_pos(t_mini *mini)
{
	int	idx;

	idx = -1;
	if (!ft_strncmp(mini->buf[0], "|", 2))
		return (mini->err.pipe);
	while (mini->buf[++idx])
	{
		if (!ft_strncmp(mini->buf[idx], "|", 2))
		{
			if (mini->buf[idx + 1] == NULL)
				return (mini->err.pipe);
			else if (!ft_strncmp(mini->buf[idx + 1], "|", 2))
				return (mini->err.pipe);
		}
	}
	return (0);
}

int	red_err_check(t_mini *mini, int idx, char in, int pipe_idx)
{
	char	rev;

	if (in == '>')
		rev = '<';
	else
		rev = '>';
	if (mini->buf[idx][1] == in && mini->buf[idx][2] != '\0')
	{
		cmd_err(&(mini->buf[idx][2]), mini->err.redirect, mini);
		return (mini->err.redirect);
	}
	else if (mini->buf[idx][1] == rev)
	{
		cmd_err(&(mini->buf[idx][1]), mini->err.redirect, mini);
		return (mini->err.redirect);
	}
	mini->red_cnt[pipe_idx]++;
	return (0);
}

int	check_redirect(t_mini *mini)
{
	int		idx;
	int		pipe_idx;
	int		ret;

	if (!mini->redirect)
		return (0);
	mini->red_cnt = (int *)ft_calloc(mini->pipe + 1, sizeof(int));
	idx = -1;
	pipe_idx = 0;
	while (mini->buf[++idx])
	{
		if (*(mini->buf[idx]) == '|')
			pipe_idx++;
		if (*(mini->buf[idx]) == '<')
			ret = red_err_check(mini, idx, '<', pipe_idx);
		else if (*(mini->buf[idx]) == '>')
			ret = red_err_check(mini, idx, '>', pipe_idx);
		if (ret == mini->err.redirect)
			return (ret);
	}
	return (0);
}

int	space_split(char *s, char space, t_mini *mini)
{
	size_t		num;

	if (s == 0)
		return (mini->err.malloc);
	num = count_arg(s, space, mini);
	mini->buf = (char **)ft_calloc((num + 1), sizeof(char *));
	if (!mini->buf || num == (size_t)mini->err.malloc)
		return (mini->err.malloc);
	if (spliting(s, space, mini->buf, mini))
		return (mini->err.malloc);
	if (check_pipe_pos(mini) == mini->err.pipe)
		return (mini->err.pipe);
	if (check_redirect(mini) == mini->err.redirect)
	{
		mini->redirect = 0;
		if (!mini->redirect)
			free(mini->red_cnt);
		return (mini->err.redirect);
	}
	return (1);
}
