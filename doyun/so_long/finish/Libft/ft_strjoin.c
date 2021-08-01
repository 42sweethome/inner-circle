/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:31:28 by doyun             #+#    #+#             */
/*   Updated: 2021/02/01 22:32:18 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*str_j;
	int				len;
	int				idx;
	int				len_s1;
	int				len_s2;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2;
	if (!(str_j = (unsigned char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		if (idx < len_s1)
			str_j[idx++] = *s1++;
		else
			str_j[idx++] = *s2++;
	}
	str_j[idx] = '\0';
	return ((char *)str_j);
}
