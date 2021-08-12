/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_space1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/08/12 18:17:23 by junghan          ###   ########.fr       */
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
		if (s[i] && s[i] != space)
		{
			mini->cnt_rvslash = 0;
			mini->cnt_quo = 0;
			start = i;
			i = quo_while(s, space, mini, i); //countc와 동일한 작업
			new[count] = (char *)ft_calloc((i - start + 1 - mini->cnt_rvslash \
						- mini->cnt_quo), sizeof(char)); //역슬래쉬와 따옴표의 갯수만큼 적게할당
			if (!new[count])
			{
				ft_free(new, count);
				return ;
			}
			scpy(new[count], &s[start], (i - start - mini->cnt_rvslash \
						- mini->cnt_quo), mini); //구분된 문자열을 new라는 이중배열에 넣어줌
			count++;
		}
		else if (s[i] == space)
			i++;
	}
}

static size_t	countc(char *s, char space, t_mini *mini) //문자열의 총 길이를 리턴하기 위한 함수
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
			i = quo_while(s, space, mini, i); // 내부적으로 큰따옴표와 작은따옴표에 관한 분류작업을함
			//if ((int)i == -2)		// ex) 따옴표의 갯수, 역슬래시 파악 등
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
		return (-1);
	num = countc(s, space, mini); 
	mini->buf = (char **)ft_calloc((num + 1), sizeof(char *));
	if (!mini->buf)
		return (-1);
	spliting(s, space, mini->buf, mini);
	return (1);
}
