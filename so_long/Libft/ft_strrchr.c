/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:24:14 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/13 15:20:35 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	long long	str_len;

	str_len = ft_strlen(str) - 1;
	if (ch == 0)
		return ((char *)(str + str_len + 1));
	while (str_len != -1)
	{
		if (*(str + str_len) == (char)ch)
			return ((char *)(str + str_len));
		str_len--;
	}
	return (0);
}
