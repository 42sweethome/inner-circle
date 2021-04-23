/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:57:29 by junghan           #+#    #+#             */
/*   Updated: 2020/12/29 11:52:23 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*fin;
	char	*tmp;

	fin = NULL;
	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (char)c)
			fin = tmp;
		tmp++;
	}
	if (*tmp == (char)c)
		fin = tmp;
	return (fin);
}
