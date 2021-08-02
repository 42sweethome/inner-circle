/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:10:46 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/12 17:00:19 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1);
	if (!(ptr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	return (ptr);
}
