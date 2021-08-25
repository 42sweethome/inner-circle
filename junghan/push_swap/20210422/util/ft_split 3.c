/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:53:08 by junghan           #+#    #+#             */
/*   Updated: 2021/04/21 18:58:56 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_getlen(char const *s, char c, int *start, int *end)
{
	*start = *end;
	while (s[*start] == c)
	{
		(*start)++;
	}
	*end = *start;
	while (s[*end] != '\0' && s[*end] != c)
	{
		(*end)++;
	}
}

int		ft_setword(char *s, char *num, int start, int end)
{
	int	i;
	int result;

	if (start < end)
	{
		i = 0;
		while (start < end)
		{
			num[i] = s[start];
			i++;
			start++;
		}
		num[i] = '\0';
	}
	result = ft_itoa(num);
	return (result);
}

int		ft_countword(char *s, char c)
{
	int	i;
	int	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	if (i == 0 && s[i] == c)
		i++;
	else if (i == 0 && s[i] != c)
	{
		i++;
		count++;
	}
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

/*
static char	**ft_freearr(char *forfree)
{
	int	i;

	i = 0;
	while (forfree[i])
	{
		free(forfree[i]);
		i++;
	}
	free(forfree);
	return (NULL);
}
*/

int		*input_int(int *tmp, int *len, char *s, char c)//stack_a를 받아서 tmp로 담아준뒤, 합쳐줌
{
	int		*arr_int;
	char	*num;
	int		count;
	int		start;
	int		end;
	int		i;

	end = 0;
	if (!s)
		return (0);
	count = ft_countword(s, c);
	if (!(arr_int = (int *)ft_calloc(count + len, sizeof(int))))
		return (-1);
	len += count;
	i = -1;
	while (i < len)
		arr_int[i] = tmp[i];
	free(tmp);// 0넣을래말래????ㅎㅎㅎㅎ 줄이 모잘랗ㅎㅎㅎㅎ
	i = -1;
	while (++i < count)
	{
		ft_getlen(s, c, &start, &end);
		if (!(num = (char *)ft_calloc(end - start + 1, sizeof(char))))
		{
			free(arr_int);
			return (-1);
		}
		arr_int[len + i] = ft_setword(s, num, start, end);
	}
	return (arr_int);
}
