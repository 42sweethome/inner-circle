/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:56:32 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/12 17:07:43 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned int	i;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		i++;
		tmp++;
	}
	return (0);
}
