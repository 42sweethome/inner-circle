/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_space1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/10/13 11:15:50 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_pipe_red(t_mini *mini, char *s, size_t *i, char space)
{
	if (s[*i] == space)
		(*i)++;
	else if (s[*i] == '|')
	{
		(*i)++;
		mini->pipe++;
	}
	else if (s[*i] == '<' || s[*i] == '>')
	{
		while (s[*i] == '<' || s[*i] == '>')
			(*i)++;
		mini->redirect++;
	}
}

size_t	count_arg(char *s, char space, t_mini *mini)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != space && s[i] != '|' && s[i] != '<' && s[i] != '>')
		{
			mini->pre_flag = 0;
			mini->env_flag = 0;
			count++;
			i = quo_while(s, space, mini, i);
			if (mini->env_flag == 1)
				count--;
			if (i == (size_t)mini->err.malloc)
				return (mini->err.malloc);
		}
		else
			count_pipe_red(mini, s, &i, space);
	}
	return (count + mini->pipe + mini->redirect);
}
