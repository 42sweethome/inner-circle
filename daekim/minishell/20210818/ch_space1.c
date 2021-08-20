/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_space1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/08/13 10:39:52 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	scpy(char *new, char *str, size_t end, t_mini *mini)
{
	size_t		start;
	int			idx;

	start = 0;
	idx = 0;
	mini->s_quo = 0;
	mini->d_quo = 0;
	while (start < end)
	{
		if (case_quo(str, &idx, mini))
			continue ;
		if (mini->d_quo == 1 && str[idx] == '\\')
			idx++;
		if (mini->s_quo == 0 && str[idx] == '$')
		{
			idx = copy_env(&new[start], str, idx, mini);
			if (idx == mini->err.malloc)
				return (mini->err.malloc);
			if (new[start] != 0)
			{
				while (new[start])
					start++;
				continue ;
			}
		}
		new[start++] = str[idx++];
	}
	return (0);
}

static int	spliting(char *s, char space, char **new, t_mini *mini)
{
	size_t		i;
	size_t		count;
	size_t		start;

	i = 0;
	count = 0;
	while (s[i])
	{			
		if (s[i] && s[i] != space)
		{
			mini->cnt_rvslash = 0;
			mini->cnt_quo = 0;
			mini->env_len = 0;
			mini->dollar = 0;
			start = i;
			i = quo_while(s, space, mini, i);
			new[count] = (char *)ft_calloc((i - start + 1 - mini->cnt_rvslash \
						- mini->cnt_quo + mini->env_len - mini->dollar), sizeof(char));
			if (!new[count] || i == (size_t)mini->err.malloc)
				return (mini->err.malloc);
			if (scpy(new[count], &s[start], (i - start - mini->cnt_rvslash \
						- mini->cnt_quo + mini->env_len - mini->dollar), mini))
				return (mini->err.malloc);
			count++;
		}
		else if (s[i] == space)
			i++;
	}
	return (0);
}

static size_t	countc(char *s, char space, t_mini *mini)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != space) 
		{
			count++;
			i = quo_while(s, space, mini, i);
			if (i == (size_t)mini->err.malloc)
				return (mini->err.malloc);
		}
		else
			i++;
	}
	return (count);
}

int	space_split(char *s, char space, t_mini *mini)
{
	size_t		num;

	if (s == 0)
		return (mini->err.malloc);
	num = countc(s, space, mini);
	mini->buf = (char **)ft_calloc((num + 1), sizeof(char *));
	if (!mini->buf || num == (size_t)mini->err.malloc)
		return (mini->err.malloc);
	if (spliting(s, space, mini->buf, mini))
	{
		ft_free(mini->buf);
		return (mini->err.malloc);
	}
	return (1);
}
