/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:34:41 by doyun             #+#    #+#             */
/*   Updated: 2021/08/01 23:31:33 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(char *s, char c)
{
	int			count;
	int			idx;

	count = 0;
	idx = 0;
	while (s[idx])
	{
		while (s[idx] == c)
			idx++;
		while (s[idx] != c && s[idx])
		{
			idx++;
			if (s[idx] == c || !(s[idx]))
				count++;
		}
	}
	return (count);
}

static int	check_start(char *s, char c, int start)
{
	int			idx;

	idx = start;
	while (s[idx] && s[idx] == c)
		idx++;
	if (s[idx] && s[idx] != c)
		return (idx);
	return (-1);
}

static int	check_end(char *s, char c)
{
	int			idx;

	idx = 0;
	while (s[idx] != c && s[idx])
		idx++;
	return (idx);
}

static void	allocate(char **split_s, char *s, char c, int idx)
{
	int			start;
	int			end;

	start = 0;
	start = check_start(s, c, start);
	while (0 <= start)
	{
		start = check_start(s, c, start);
		end = check_end(&s[start], c);
		split_s[++idx] = ft_substr(s, start, end);
		if (!(split_s[idx]))
		{
			while (idx > 0)
			{
				free(split_s[--idx]);
				split_s[idx] = 0;
			}
			free(split_s);
			split_s = 0;
			return ;
		}
		start = start + end;
	}
	split_s[idx] = 0;
}

char	**ft_split(char const *s, char c)
{
	char		**split_s;
	int			low;
	int			idx;

	if (!s)
		return (0);
	low = count_char((char *)s, c);
	split_s = (char **)malloc(sizeof(char *) * (low + 1));
	if (!split_s)
		return (0);
	idx = -1;
	allocate(split_s, (char *)s, c, idx);
	return (split_s);
}
