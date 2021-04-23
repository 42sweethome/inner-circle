/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:30:10 by junghan           #+#    #+#             */
/*   Updated: 2020/12/24 01:48:29 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tmp_str;
	unsigned char	target;

	tmp_str = (unsigned char *)str;
	target = c;
	while (n--)
	{
		if (*tmp_str == target)
			return ((void *)tmp_str);
		tmp_str++;
	}
	return (0);
}
