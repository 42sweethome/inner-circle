/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:41:26 by daekim            #+#    #+#             */
/*   Updated: 2020/12/31 19:51:44 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char *i;

	i = 0;
	while (*src)
	{
		if (*src == (char)c)
			i = (char *)src;
		src++;
	}
	if (c == 0)
		return ((char *)src);
	else if (i == 0)
		return (0);
	else
		return (i);
}
