/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:14:39 by daekim            #+#    #+#             */
/*   Updated: 2021/01/01 22:32:04 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	size_t	size;

	if (s == 0)
		return (0);
	size = 0;
	while (s[size])
		size++;
	s1 = malloc(sizeof(char) * (len + 1));
	if (s1 == 0)
		return (0);
	i = 0;
	while (i < len && start + i < size)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
