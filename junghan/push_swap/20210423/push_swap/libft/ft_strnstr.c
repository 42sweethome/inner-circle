/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:30:24 by junghan           #+#    #+#             */
/*   Updated: 2020/12/25 00:32:16 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;

	if (!*s2)
		return ((char *)s1);
	s2_len = ft_strlen(s2);
	while (*s1 && s2_len <= n)
	{
		if (!ft_strncmp(s1, s2, s2_len))
			return ((char *)s1);
		s1++;
		n--;
	}
	return (0);
}
