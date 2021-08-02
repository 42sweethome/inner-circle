/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:11:23 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/13 15:21:14 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char*)s1 - *(unsigned char *)s2);
		n--;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char*)s2);
}
