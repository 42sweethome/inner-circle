/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:28:28 by sonkang           #+#    #+#             */
/*   Updated: 2021/08/02 23:10:55 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	size;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (size <= start)
	{
		str[0] = '\0';
		return (str);
	}
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
