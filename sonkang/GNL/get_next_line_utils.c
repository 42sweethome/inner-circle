/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:36 by sonkang           #+#    #+#             */
/*   Updated: 2021/03/17 19:21:43 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char				*ft_strdup(const char *s1)
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

char				*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		str_len;
	char	*str;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char *)malloc(str_len * sizeof(char))))
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (*(s2 + i) != '\0')
	{
		*(str + ft_strlen(s1) + i) = *(s2 + i);
		i++;
	}
	*(str + str_len - 1) = '\0';
	return (str);
}
