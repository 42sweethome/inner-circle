/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:55:44 by junghan           #+#    #+#             */
/*   Updated: 2021/05/10 16:33:11 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		idx++;
	}
	return (idx);
}

size_t	ft_strlcpy2(char *dest, char *src, size_t destsize)
{
	size_t	idx;
	size_t	cnt;

	idx = 0;
	cnt = 0;
	while (src[cnt] != '\0')
		cnt++;
	if (destsize != 0)
	{
		while (src[idx] && idx + 1 < destsize)
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (cnt);
}

size_t	ft_strlcat2(char *dest, char *src, size_t size)
{
	size_t	idx;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen2(dest);
	src_len = ft_strlen2(src);
	idx = 0;
	if (size < dest_len + 1)
		return (size + src_len);
	while (src[idx] && (dest_len + idx + 1) < size)
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	return (src_len + dest_len);
}

char	*ft_strdup2(char *s1)
{
	char	*result;
	size_t	len;

	len = ft_strlen2(s1);
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strlcpy2(result, s1, len + 1);
	return (result);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	char	*result;
	size_t	len;

	if (!str1 || !str2)
		return (0);
	len = ft_strlen2(str1) + ft_strlen2(str2);
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strlcpy2(result, str1, len + 1);
	ft_strlcat2(result, str2, len + 1);
	return (result);
}
