/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 09:07:38 by daekim            #+#    #+#             */
/*   Updated: 2021/08/02 09:01:32 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t size)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (!ss1 || !ss2)
		return (-1);
	while (size--)
	{
		if (*ss1 != *ss2 || *ss1 == 0)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	return (0);
}
