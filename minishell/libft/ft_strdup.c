/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:34:53 by daekim            #+#    #+#             */
/*   Updated: 2021/10/06 18:32:23 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	while (s1 && s1[len])
		len++;
	s = malloc(sizeof(char) * (len + 1));
	if (s == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
