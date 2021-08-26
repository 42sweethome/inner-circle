/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.ck>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 19:46:10 by daekim            #+#    #+#             */
/*   Updated: 2020/12/31 19:46:30 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t size)
{
	unsigned char *dest;

	dest = src;
	while (size-- > 0)
	{
		*dest = 0;
		dest++;
	}
}
