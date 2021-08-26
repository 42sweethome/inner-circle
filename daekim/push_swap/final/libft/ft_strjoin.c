/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:35:42 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 04:42:22 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char))))
		return (0);
	str = new;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	return (new);
}
