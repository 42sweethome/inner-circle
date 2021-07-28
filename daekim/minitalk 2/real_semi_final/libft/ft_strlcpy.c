/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:41:55 by junghan           #+#    #+#             */
/*   Updated: 2021/07/16 16:01:02 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t dest_size)
{
	size_t	i;
	size_t	src_len;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dest_size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < src_len && i + 1 < dest_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
