/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/10/14 14:59:29 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_offset(char *new, size_t *start)
{
	if (new[*start] != 0)
	{
		while (new[*start])
			(*start)++;
		return (1);
	}
	else
		return (1);
	return (0);
}

int	split_copy(char *new, char *str, size_t end, t_mini *mini)
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
		if (mini->s_quo == 0 && str[idx] == '$')
		{
			idx = copy_env(&new[start], str, idx, mini);
			if (idx == mini->err.malloc)
				return (mini->err.malloc);
			if (change_offset(new, &start))
				continue ;
		}
		new[start++] = str[idx++];
		if (str[idx - 1] == '\0')
			break ;
	}
	return (0);
}
