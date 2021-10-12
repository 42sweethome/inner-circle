/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_space2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/09/09 17:55:04 by junghan          ###   ########.fr       */
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

int	check_quo(char *s, char c, int i, t_mini *mini) // s: 주어진 문자열 c: 큰/작은 따옴표 i:인덱스 mini:정보꾸러미
{
	mini->pre_flag = 1;
	while (s[++i] && s[i] != c) //큰따옴표인 경우 역슬래시를 출력하지 않아야함 r_value 고로 mini꾸러미에 담아줌
	{				//닫는 따옴표 혹은 null terminated가 되기 전까지 인덱스를 더함
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
	if (s[i] == c) // 닫는 따옴표가 나온경우
		mini->cnt_quo += 2;
	if (s[i] == 0) // 따옴표 갯수가 홀수로 끝나는 경우
	{
		mini->odd_quo = 1;
		i--;
	}
	return (i);
}

int	quo_while(char *s, char space, t_mini *mini, int i)
{
	int check;

	check = 0;
	while (s[i] && s[i] != space && s[i] != '|' && s[i] != '<' && s[i] != '>') //중복?
	{
		if (s[i] == '\'') //최초 열린 따옴표가 작은따옴표인지 큰따옴표인지 구분
			i = check_quo(s, '\'', i, mini);
		else if (s[i] == '"')
			i = check_quo(s, '"', i, mini);
		else if (s[i] == '$')
		{
			check = i;
			i = check_env(s, i, mini);
			if (mini->env_flag == 0)
				mini->pre_flag = 1;
			if ((s[check + 1] == ' ' || s[check + 1] == 0) || (s[check + 1] != '?' && !special_char2(s[i + 1])))
				mini->env_flag = 0;//할당할겨
		}//$만 연속적으로 들어오는 부분에서 할당문제가 있음.
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
