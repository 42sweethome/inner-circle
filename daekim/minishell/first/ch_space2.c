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

int	check_quo(char *s, char c, int i, t_mini *mini)
{
	int j;

	mini->quo = 1;
	while (s[++i] && s[i] != c)
	{
		if (s[i] == '\\')
		{
			s[i + 1] = '"';
			i++;
		}
	}
	if (s[i] == 0)
		return (-1);
	return (i);
}

int	quo_while(char *s, char c, t_mini *mini, int i)
{
	while (s[i] && s[i] != c)
	{
		if (s[i] == '\'')
			i = check_quo(s, '\'', i, mini);
		else if (s[i] == '"')
			i = check_quo(s, '"', i, mini);
		if (i == -1)
			return (-1);
		i++;
	}
	return (i);
}
