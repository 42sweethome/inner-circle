/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:22:14 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:16:50 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == 0 && s == 0)
		return (dest);
	while (size-- > 0)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
