/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 03:26:19 by doyun             #+#    #+#             */
/*   Updated: 2021/08/01 15:58:20 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_len(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*str_join(char *s1, char *s2)
{
	char	*str_j;
	int		len;
	int		idx;
	int		len_s1;
	int		len_s2;

	len_s1 = str_len(s1);
	len_s2 = str_len(s2);
	len = len_s1 + len_s2;
	str_j = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_j)
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

char	*sub_str(char *s, int start, size_t len)
{
	char			*dest;
	char			*src;
	unsigned int	idx;

	src = s;
	dest = (char *)malloc(sizeof(char) * (len + 1))
	if (!dest || !s)
		return (NULL);
	idx = 0;
	while (idx < len && src[start] && !(start > str_len(src)))
	{
		dest[idx] = src[start];
		idx++;
		start++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*str_dup(char *s1)
{
	char	*temp_s1;
	int		len;
	int		idx;

	if (!s1)
		return (NULL);
	len = str_len(s1) + 1;
	temp_s1 = (char *)malloc(sizeof(char) * len);
	if (temp_s1 == 0)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		temp_s1[idx] = s1[idx];
		idx++;
	}
	temp_s1[idx] = '\0';
	return (temp_s1);
}
