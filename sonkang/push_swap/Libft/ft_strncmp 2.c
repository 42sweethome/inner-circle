/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 03:26:52 by doyun             #+#    #+#             */
/*   Updated: 2021/06/22 21:07:09 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			idx;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	idx = 0;
	while (idx < n)
	{
		if (temp_s1[idx] == temp_s2[idx])
			idx++;
		else
			break ;
	}
	if (temp_s1[idx] == '\0' && temp_s2[idx] == '\0')
		return (1);
	else
		return (0);
}
