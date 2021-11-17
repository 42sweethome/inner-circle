/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_space2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/11/17 11:11:23 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	case_quo(char *str, int *idx, t_mini *mini)
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
	mini->pre_flag = 1;
	while (s[++i] && s[i] != c)
	{
		if (c == '"' && s[i] == '$')
		{
			mini->d_quo = 1;
			i = check_env(s, i, mini);
			mini->env_flag = 0;
			mini->d_quo = 0;
		}
		if (i == mini->err.malloc)
			return (mini->err.malloc);
	}
	if (s[i] == c)
		mini->cnt_quo += 2;
	if (s[i] == 0)
	{
		mini->odd_quo = 1;
		i--;
	}
	return (i);
}

void	check_dollar(t_mini *mini, char *s, int i, int check)
{
	check = i;
	i = check_env(s, i, mini);
	if (mini->env_flag == 0)
		mini->pre_flag = 1;
	if ((s[check + 1] == ' ' || s[check + 1] == 0) \
	|| (s[check + 1] != '?' && !special_char2(s[i + 1])))
		mini->env_flag = 0;
}

int	quo_while(char *s, char space, t_mini *mini, int i)
{
	int	check;

	check = 0;
	while (s[i] && s[i] != space && s[i] != '|' && s[i] != '<' && s[i] != '>')
	{
		if (s[i] == '\'')
			i = check_quo(s, '\'', i, mini);
		else if (s[i] == '"')
			i = check_quo(s, '"', i, mini);
		else if (s[i] == '$')
			check_dollar(mini, s, i, check);
		else
			mini->pre_flag = 1;
		if (i == mini->err.malloc)
			return (mini->err.malloc);
		i++;
	}
	if (mini->pre_flag)
		mini->env_flag = 0;
	return (i);
}
