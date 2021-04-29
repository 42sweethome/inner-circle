/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:53:08 by junghan           #+#    #+#             */
/*   Updated: 2021/04/26 16:30:52 by junghan          ###   ########.fr       */
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

int	input_int(t_link *st_a, char *s, char c, int *len)
{
	char	*num;
	int		count;
	int		content;
	int		start;
	int		end;
	int		i;

	end = 0;
	if (!s)
		return (0);
	count = ft_countword(s, c);
	i = -1;
	while (++i < count)
	{
		ft_getlen(s, c, &start, &end);
		if (!(num = (char *)ft_calloc(end - start + 1, sizeof(char))))
		{
			return (0);
		}
		content = ft_setword(s, num, start, end);
		st_a->node = lstnew(content, len);
		lstadd_back(&st_a->head, &st_a->tail,st_a->node);
	}
	return (1);
}
