/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:38:56 by daekim            #+#    #+#             */
/*   Updated: 2020/12/31 19:51:22 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *src, int c)
{
	while (*src)
	{
		if (*src == (char)c)
			return ((char *)src);
		src++;
	}
	if (c == 0)
		return ((char *)src);
	return (0);
}
