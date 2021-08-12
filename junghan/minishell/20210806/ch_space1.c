/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:11:34 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	scpy(char *new, char *str, size_t end, t_mini *mini)
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
		new[start++] = str[idx++];
	}
}

static char	ft_free(char **new, size_t num)
{
	size_t		i;

	i = 0;
	while (i < num)
		free(new[i++]);
	free(new);
	return (0);
}

static void	spliting(char *s, char space, char **new, t_mini *mini)
{
	size_t		i;
	size_t		count;
	size_t		start;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != space) //c == space
		{
			start = i;
			i = quo_while(s, space, mini, i);
			new[count] = (char *)ft_calloc((i - start + 1 - mini->cnt_rvslash \
						- mini->cnt_quo), sizeof(char));
			if (!new[count])
			{
				ft_free(new, count);
				return ;
			}
			scpy(new[count], &s[start], i - start, mini);
			count++;
		}
		else if (s[i] == space)
			i++;
	}
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
			if ((int)i == -1)
				return (-1);
		}
		else
			i++;
	}
	return (count);
}

char	**space_split(char *s, char space, t_mini *mini)
{
	char		**new;
	size_t		num;

	if (s == 0)
		return (0);
	num = countc(s, space, mini);
	if ((int)num == -1)
		return (0);
	new = (char **)ft_calloc((num + 1), sizeof(char *));
	if (!new)
		return (0);
	spliting(s, space, new, mini);
	return (new);
}
