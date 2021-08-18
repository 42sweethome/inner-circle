/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 23:41:32 by sonkang           #+#    #+#             */
/*   Updated: 2021/08/02 23:18:17 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	tmp_s1 = (const unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;
	if (!n)
		return (0);
	while (n > 1 && *tmp_s1 == *tmp_s2)
	{
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	return (*tmp_s1 - *tmp_s2);
}
