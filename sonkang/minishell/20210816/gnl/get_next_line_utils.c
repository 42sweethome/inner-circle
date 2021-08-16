/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:21:02 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:28:12 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup2(char *str)
{
	char	*temp;
	size_t	len;
	size_t	i;

	len = ft_strlen2(str);
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (0);
	i = 0;
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new;
	size_t	i;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strdup2(s2));
	if (s2 == 0)
		return (ft_strdup2(s1));
	new = (char *)malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!new)
		return (0);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	while (*s2)
	{
		new[i++] = *s2;
		s2++;
	}
	new[i] = 0;
	return (new);
}
