/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:46:55 by doyun             #+#    #+#             */
/*   Updated: 2021/02/03 02:38:54 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;
	unsigned int	idx;

	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	idx = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (n)
	{
		*temp_d = *temp_s;
		if (*temp_s == (unsigned char)c)
			return (temp_d + 1);
		temp_d++;
		temp_s++;
		n--;
	}
	return (0);
}
