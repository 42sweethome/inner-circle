/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:53:08 by junghan           #+#    #+#             */
/*   Updated: 2021/04/21 19:28:25 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	result = ft_atoi(num);
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

int		*input_int(int *tmp, int *len, char *s, char c)
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
	if (!(arr_int = (int *)ft_calloc((size_t)(count + *len), sizeof(int))))
		return (0);
	i = -1;
	while (++i < *len && tmp)
		arr_int[i] = tmp[i];
	free(tmp);
	i = -1;
	while (++i < count)
	{
		ft_getlen(s, c, &start, &end);
		if (!(num = (char *)ft_calloc(end - start + 1, sizeof(char))))
		{
			free(arr_int);
			return (0);
		}
		arr_int[*len + i] = ft_setword(s, num, start, end);
	}
	*len += count;
	return (arr_int);
}
