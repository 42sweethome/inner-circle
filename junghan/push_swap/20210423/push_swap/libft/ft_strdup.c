/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:05:29 by junghan           #+#    #+#             */
/*   Updated: 2020/12/27 17:15:16 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s1);
	if (!(tmp = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strlcpy(tmp, s1, len + 1);
	return (tmp);
}
