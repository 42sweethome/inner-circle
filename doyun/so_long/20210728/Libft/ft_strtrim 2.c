/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:12:26 by doyun             #+#    #+#             */
/*   Updated: 2021/02/04 23:29:31 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check(char s1, char *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*temp_s1;
	size_t		check_f;
	size_t		check_l;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	check_f = 0;
	while (check((char)s1[check_f], (char *)set))
	{
		check_f++;
	}
	check_l = ft_strlen(s1) - 1;
	while (check((char)s1[check_l], (char *)set))
	{
		check_l--;
		if (check_f >= check_l)
			return (ft_strdup(""));
	}
	len = check_l - check_f + 1;
	if (!(temp_s1 = (char *)ft_substr((char *)s1, (int)check_f, len)))
		return (0);
	return ((char *)temp_s1);
}
