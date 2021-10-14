/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/10/14 15:11:57 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_init(t_mini *mini)
{
	mini->pre_flag = 0;
	mini->env_flag = 0;
	mini->cnt_quo = 0;
	mini->env_len = 0;
	mini->dollar = 0;
}

int	split_pipe_red(char *s, char **new, size_t *i, size_t *count)
{
	int	j;

	if (s[*i] == ' ')
		(*i)++;
	else if (s[*i] == '|')
	{
		new[*count] = ft_strdup("|");
		if (new[*count] == 0)
			return (-1);
		(*i)++;
		(*count)++;
	}
	else if (s[*i] == '<' || s[*i] == '>')
	{
		j = *i;
		while (s[*i] == '<' || s[*i] == '>')
			(*i)++;
		new[*count] = ft_substr(&s[j], 0, *i - j);
		if (new[*count] == 0)
			return (-1);
		(*count)++;
	}
	return (0);
}

int	new_copy(t_mini *mini, char **new, char *s, size_t *count)
{
	*new = (char *)ft_calloc((mini->split_size + 1), sizeof(char));
	if (!*new)
		return (mini->err.malloc);
	if (split_copy(*new, s, mini->split_size, mini))
		return (mini->err.malloc);
	(*count)++;
	return (0);
}

int	spliting(char *s, char space, char **new, t_mini *mini)
{
	size_t	i;
	size_t	count;
	size_t	start;

	i = 0;
	count = 0;
	while (s[i])
	{			
		if (s[i] && s[i] != space && s[i] != '|' && s[i] != '<' && s[i] != '>')
		{
			split_init(mini);
			start = i;
			i = quo_while(s, space, mini, i);
			if (mini->env_flag == 1)
				continue ;
			mini->split_size = i - start - mini->cnt_quo \
				+ mini->env_len - mini->dollar;
			if ((int)i == -1 || new_copy(mini, &new[count], &s[start], &count))
				return (mini->err.malloc);
		}
		else
			if (split_pipe_red(s, new, &i, &count) == -1)
				return (mini->err.malloc);
	}
	return (0);
}
