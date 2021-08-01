/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:35:46 by doyun             #+#    #+#             */
/*   Updated: 2021/08/01 17:36:53 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp_s;

	temp_s = (char *)s;
	while (*temp_s)
	{
		if (*temp_s == (char)c)
			return ((char *)temp_s);
		temp_s++;
	}
	if (*temp_s == (char)c)
		return (temp_s);
	return (0);
}
