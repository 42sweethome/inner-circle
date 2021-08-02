/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:23:17 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/12 16:59:36 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_size;

	if (!dst || !src)
		return (0);
	src_size = ft_strlen(src);
	if (size)
	{
		while (--size && *src)
		{
			*dst = *src;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (src_size);
}
