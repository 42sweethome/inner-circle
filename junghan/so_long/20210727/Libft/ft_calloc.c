/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:23:40 by doyun             #+#    #+#             */
/*   Updated: 2021/02/02 22:51:26 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;

	if (!(mem = malloc(size * count)))
	{
		return (NULL);
	}
	ft_bzero(mem, (size * count));
	return (mem);
}
