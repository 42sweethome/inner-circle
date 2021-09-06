/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:51:21 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:03:05 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check2(char *s1, char *set, size_t *j)
{
	size_t	end;
	size_t	i;

	end = 0;
	while (s1[end])
		end++;
	i = 0;
	while (set[i])
	{
		if (s1[end - 1] == set[i] && end > 0)
		{
			i = -1;
			end--;
		}
		i++;
	}
	*j = end;
}

static void	check1(char *s1, char *set, size_t *i)
{
	size_t	begin;
	size_t	j;

	begin = *i;
	j = 0;
	while (set[j] && s1[begin])
	{
		if (s1[begin] == set[j])
		{
			j = -1;
			begin++;
		}
		j++;
	}
	*i = begin;
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s1 == 0)
		return (0);
	i = 0;
	check1(s1, set, &i);
	if (s1[i] == 0)
		return (ft_strdup(""));
	j = 0;
	check2(s1, set, &j);
	if (i >= j)
		i = 0;
	new = malloc(sizeof(char) * (j - i + 1));
	if (!new)
		return (0);
	k = -1;
	while (++k + i < j)
		new[k] = s1[k + i];
	new[k] = '\0';
	return (new);
}
