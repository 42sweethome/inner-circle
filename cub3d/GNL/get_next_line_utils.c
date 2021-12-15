/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:36 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/15 17:50:25 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		str_len;
	char	*str;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(str_len * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (*(s1 + ++i) != '\0')
		*(str + i) = *(s1 + i);
	i = -1;
	while (*(s2 + ++i) != '\0')
		*(str + ft_strlen(s1) + i) = *(s2 + i);
	*(str + str_len - 1) = '\0';
	return (str);
}
