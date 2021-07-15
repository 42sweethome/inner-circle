/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:10:51 by junghan           #+#    #+#             */
/*   Updated: 2020/12/28 20:37:06 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	unsigned char	target;
	size_t			i;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	target = c;
	i = 0;
	while (n > i)
	{
		tmp_dest[i] = tmp_src[i];
		if (target == tmp_src[i])
			return (dest + (i + 1));
		i++;
	}
	return (0);
}
