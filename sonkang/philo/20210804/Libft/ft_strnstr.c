/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:02:42 by doyun             #+#    #+#             */
/*   Updated: 2021/08/01 17:23:00 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hst_idx;
	size_t	ndl_idx;

	if (*needle == '\0')
		return ((char *)haystack);
	hst_idx = 0;
	while (haystack[hst_idx] != '\0' && hst_idx < len)
	{
		ndl_idx = 0;
		while (haystack[hst_idx + ndl_idx] == needle[ndl_idx]
			&& ndl_idx < len - hst_idx)
		{
			ndl_idx++;
			if (needle[ndl_idx] == '\0')
				return ((char *)&haystack[hst_idx]);
		}
		hst_idx++;
	}
	return (0);
}
