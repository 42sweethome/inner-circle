/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:23:58 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/12 16:55:38 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int start;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && *(haystack + i) != '\0')
	{
		if (*(haystack + i) == *needle)
		{
			start = i;
			while (*(haystack + i) == *(needle + i - start)
					&& *(needle + i - start) != '\0' && i < len)
				i++;
			if (*(needle + i - start) == '\0')
				return ((char *)(haystack + start));
			i--;
		}
		i++;
	}
	return (NULL);
}
