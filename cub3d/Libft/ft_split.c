/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:22:58 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/15 17:10:23 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int		count;
	int		i;

	if (!s[0])
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static void	free_str(char **str, int j)
{
	int		i;

	i = 0;
	while (i < j)
		free(str[i++]);
	free(str);
}

static void	fill_str(char *str, char const *s, int start, int end)
{
	int		i;

	i = 0;
	while (start < end)
		str[i++] = s[start++];
}

static void	ft_str(char **str, char const *s, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	j = 0;
	while (s[i])
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[j] = (char *)ft_calloc((i - start + 1), sizeof(char));
		if (!str[j])
		{
			free_str(str, j);
			return ;
		}
		fill_str(str[j], s, start, i);
		while (s[i] && s[i] == c)
			i++;
		j++;
	}
}
#include <stdio.h>
char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	if (s == 0)
		return (0);
	count = ft_count(s, c);
	str = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!str)
		return (NULL);
	ft_str(str, s, c);
	return (str);
}
