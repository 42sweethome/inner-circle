/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:31:16 by doyun             #+#    #+#             */
/*   Updated: 2021/02/02 22:59:51 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*temp_s;
	int				len;

	temp_s = (unsigned char *)s;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (temp_s[len] == (unsigned char)c)
			return ((char *)&temp_s[len]);
	}
	return (0);
}
