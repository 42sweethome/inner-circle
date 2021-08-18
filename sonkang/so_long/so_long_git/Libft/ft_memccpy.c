/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:39:04 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/12 17:07:56 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dest);
		src++;
		n--;
	}
	return (NULL);
}
