/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:34:53 by daekim            #+#    #+#             */
/*   Updated: 2021/01/01 22:31:46 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
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
