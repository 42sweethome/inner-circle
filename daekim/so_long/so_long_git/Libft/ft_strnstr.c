/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 08:59:39 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:01:19 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (*src == 0)
		return ((char *)dest);
	i = 0;
	while (dest[i] && i < size)
	{
		j = 0;
		if (dest[i] == src[j])
		{
			while (src[j] && j < size - i)
			{
				if (dest[i + j] != src[j])
					break ;
				j++;
			}
			if (src[j] == 0)
				return ((char *)&dest[i]);
		}
		i++;
	}
	return (0);
}
