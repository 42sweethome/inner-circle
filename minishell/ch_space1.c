/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_space1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/09/02 16:20:39 by junghan          ###   ########.fr       */
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
//		printf("start : %zu end : %zu\n", start, end);
		if (case_quo(str, &idx, mini))
			continue ;
		if (mini->s_quo == 0 && str[idx] == '$')
		{
			idx = copy_env(&new[start], str, idx, mini);	
	//		printf("new : %c\n", new[start]);
			if (idx == mini->err.malloc)
				return (mini->err.malloc);
			if (new[start] != 0)
			{
				while (new[start])
					start++;
				continue ;
			}
			else
				continue ;
		}
		new[start++] = str[idx++];
		if (str[idx - 1] == '\0')
			break ;
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
		if (s[i] && s[i] != space && s[i] != '|')
		{
			mini->quo_flag = 0;
			mini->pre_flag = 0;
			mini->env_flag = 0;
			mini->cnt_quo = 0;
			mini->env_len = 0;
			mini->dollar = 0;
			start = i;
			i = quo_while(s, space, mini, i); //countc와 동일한 작업
			if (mini->env_flag == 1)
				continue ;
		//	printf("count : %lu\n", i - start + 1 - mini->cnt_quo + mini->env_len - mini->dollar - mini->quo_flag);

	//		printf("i      : %zu, start   : %zu, cnt_quo : %d, env_len	: %d\n", i, start, mini->cnt_quo, mini->env_len);
	//		printf("dollar : %d, quo_flag : %d, env_flag : %d\n", mini->dollar, mini->quo_flag, mini->env_flag);
			new[count] = (char *)ft_calloc((i - start + 1 \
						- mini->cnt_quo + mini->env_len - mini->dollar - mini->quo_flag), sizeof(char)); //역슬래쉬와 따옴표의 갯수만큼 적게할당
			if (!new[count] || i == (size_t)mini->err.malloc)
				return (mini->err.malloc);
		//	if (mini->quo_flag == 0)
		//	{
				if (scpy(new[count], &s[start], (i - start \
						- mini->cnt_quo + mini->env_len - mini->dollar - mini->quo_flag), mini))//구분된 문자열을 new라는 이중배열에 넣어줌
				return (mini->err.malloc);
		//	}
			count++;
		}
		else if (s[i] == space)
			i++;
		else if (s[i] == '|')
		{
			new[count] = ft_strdup("|");
			if (new[count] == 0)
				return (mini->err.malloc);
			i++;
			count++;
		}
	}
	return (0);
}

static size_t	countc(char *s, char space, t_mini *mini) //문자열의 총 길이를 리턴하기 위한 함수
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != space && s[i] != '|') 
		{
			mini->pre_flag = 0;
			mini->env_flag = 0;
			count++;
			i = quo_while(s, space, mini, i); // 내부적으로 큰따옴표와 작은따옴표에 관한 분류작업을함
			//if ((int)i == -2)		// ex) 따옴표의 갯수, 역슬래시 파악 등
			if (mini->env_flag == 1)
				count--;
			if (i == (size_t)mini->err.malloc)
				return (mini->err.malloc);
		}
		else if (s[i] == space)
			i++;
		else if (s[i] == '|')
		{
			i++;
			mini->pipe++;
		}
	}
	return (count + mini->pipe);
}

int	check_pipe_pos(t_mini *mini)
{
	int idx;

	idx = -1;
	if (!ft_strncmp(mini->buf[0], "|", 2))
		return (mini->err.pipe);
	while(mini->buf[++idx])
	{
		if (!ft_strncmp(mini->buf[idx], "|", 2))
		{
			if (mini->buf[idx + 1] == NULL)
				return (mini->err.pipe);
			else if (!ft_strncmp(mini->buf[idx + 1], "|", 2))
				return (mini->err.pipe);
		}
	}
	return (0);
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
		return (mini->err.malloc);
	if (check_pipe_pos(mini) == mini->err.pipe)
		return (mini->err.pipe);
	return (1);
}
