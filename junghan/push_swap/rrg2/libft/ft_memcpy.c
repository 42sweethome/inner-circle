/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 02:11:27 by junghan           #+#    #+#             */
/*   Updated: 2020/12/28 20:37:27 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *tmp_dest;
	unsigned char *tmp_src;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n > 0)
	{
		*tmp_dest = *tmp_src;
		tmp_dest++;
		tmp_src++;
		n--;
	}
	return (dest);
}
