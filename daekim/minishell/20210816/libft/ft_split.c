/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:42 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:11:34 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	scpy(char *new, char *s, size_t i, size_t start)
{
	size_t		j;

	j = 0;
	while (start < i)
	{
		new[j] = s[start];
		start++;
		j++;
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

static void	spliting(char *s, char c, char **new)
{
	size_t		i;
	size_t		count;
	size_t		start;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			new[count] = (char *)ft_calloc((i - start + 1), sizeof(char));
			if (!new[count])
			{
				ft_free(new, count);
				return ;
			}
			scpy(new[count], s, i, start);
			count++;
		}
		else if (s[i] == c)
			i++;
	}
}

static size_t	countc(char *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char		**new;
	size_t		num;

	if (s == 0)
		return (0);
	num = countc(s, c);
	new = (char **)ft_calloc((num + 1), sizeof(char *));
	if (!new)
		return (0);
	spliting(s, c, new);
	return (new);
}
