/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 09:11:35 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:17:15 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t size)
{
	unsigned char	*s;

	s = (unsigned char *)src;
	while (size-- > 0)
	{
		if (*s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (0);
}
