/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:29:53 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/13 15:20:14 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int	find_end(char const *s1, char const *set, int len)
{
	int		i;

	while (len)
	{
		i = 0;
		while (set[i])
		{
			if (s1[len] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			break ;
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	start = find_start(s1, set);
	end = find_end(s1, set, ft_strlen(s1) - 1);
	len = end - start + 1;
	if (start >= end)
		return (ft_strdup(""));
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	ft_strlcpy(str, s1 + start, len + 1);
	return (str);
}
