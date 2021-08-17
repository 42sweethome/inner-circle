/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:02:28 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:13:16 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t size)
{
	unsigned char	*dest;

	dest = src;
	while (size-- > 0)
	{
		*dest = (char)c;
		dest++;
	}
	return (src);
}
