/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:53:08 by junghan           #+#    #+#             */
/*   Updated: 2021/05/18 21:45:03 by junghan          ###   ########.fr       */
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

ssize_t		ft_setword(char *s, char *num, int start, int end)
{
	int		i;
	ssize_t	result;

	i = 0;
	while (start < end)
	{
		num[i] = s[start];
		i++;
		start++;
	}
	num[i] = '\0';
	result = ft_atoi(num);
	return (result);
}

int			ft_countword(char *s, char c)
{
	int		i;
	int		count;

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

int			input_int(t_link *st_a, char *s, char c, int *len)
{
	char	*num;
	ssize_t	content;
	int		i;
	t_info	info;

	init_info(&info);
	if (!s)
		return (-1);
	if ((info.count = ft_countword(s, c)) == 0)
		return (-1);
	i = -1;
	while (++i < info.count)
	{
		ft_getlen(s, c, &info.start, &info.end);
		if (!(num = (char *)ft_calloc(info.end - info.start + 1, sizeof(char))))
			return (-1);
		content = ft_setword(s, num, info.start, info.end);
		free(num);
		num = 0;
		if (content == 2147483649)
			return (-1);
		st_a->node = lstnew(content, len);
		lstadd_back(&st_a->head, &st_a->tail, st_a->node);
	}
	return (1);
}
