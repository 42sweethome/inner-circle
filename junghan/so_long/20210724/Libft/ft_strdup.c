/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:32:48 by doyun             #+#    #+#             */
/*   Updated: 2021/02/01 22:37:09 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	unsigned char	*temp_s1;
	int				len;
	int				idx;

	len = ft_strlen(s1) + 1;
	temp_s1 = (unsigned char *)malloc(sizeof(char) * len);
	if (temp_s1 == 0)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		temp_s1[idx] = s1[idx];
		idx++;
	}
	temp_s1[idx] = '\0';
	return ((char *)temp_s1);
}
