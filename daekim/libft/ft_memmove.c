/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmover.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@stdent.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:16:59 by daekim            #+#    #+#             */
/*   Updated: 2020/12/31 19:47:42 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d <= s)
		while (size-- > 0 && s)
		{
			*d = *s;
			d++;
			s++;
		}
	else
	{
		d += size;
		s += size;
		while (size-- > 0 && d)
		{
			d--;
			s--;
			*d = *s;
		}
	}
	return (dest);
}
