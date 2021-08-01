/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:36:24 by doyun             #+#    #+#             */
/*   Updated: 2021/08/01 17:20:29 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned int	idx;

	src = (unsigned char *)s;
	dest = (unsigned char *)malloc(sizeof(char) * (len + 1));
	if (!dest || !s)
		return (0);
	idx = 0;
	while (idx < len && src[start] && !(start > ft_strlen((char *)src)))
	{
		dest[idx] = src[start];
		idx++;
		start++;
	}
	dest[idx] = '\0';
	return ((char *)dest);
}
