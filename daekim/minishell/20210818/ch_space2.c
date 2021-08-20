/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_space2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/08/12 18:19:01 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	case_quo(char * str, int *idx, t_mini *mini)
{
	if (str[*idx] == '\'' && mini->d_quo == 0)
	{
		if (mini->s_quo == 0)
			mini->s_quo = 1;
		else if (mini->s_quo == 1)
			mini->s_quo = 0;
		(*idx)++;
		return (1);
	}
	else if (str[*idx] == '"' && mini->s_quo == 0)
	{
		if (mini->d_quo == 0)
			mini->d_quo = 1;
		else if (mini->d_quo == 1)
			mini->d_quo = 0;
		(*idx)++;
		return (1);
	}
	return (0);
}

int	check_quo(char *s, char c, int i, t_mini *mini)
{
	while (s[++i] && s[i] != c)
	{
		if (s[i] == '\\' && s[i + 1] == '"')
		{
			mini->cnt_rvslash++;
			i++;
		}
		if (c == '"' && s[i] == '$')
			i = check_env(s, i, mini);
		if (i == mini->err.malloc)
			return (mini->err.malloc);
	}
	if (s[i] == c)
		mini->cnt_quo += 2;
	if (s[i] == 0)
		mini->odd_quo = 1;
	return (i);
}

int	quo_while(char *s, char space, t_mini *mini, int i)
{
	while (s[i] && s[i] != space)
	{
		if (s[i] == '\'')
			i = check_quo(s, '\'', i, mini);
		else if (s[i] == '"')
			i = check_quo(s, '"', i, mini);
		else if (s[i] == '$')
			i = check_env(s, i, mini);
		if (i == mini->err.malloc)
			return (mini->err.malloc);
		i++;
	}		
	return (i);
}
