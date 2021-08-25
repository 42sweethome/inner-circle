/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:59:41 by junghan           #+#    #+#             */
/*   Updated: 2020/12/24 01:52:23 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;
	char	*tmp;

	target = (char)c;
	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == target)
			return (tmp);
		tmp++;
	}
	if (*tmp == target)
		return (tmp);
	return (0);
}
