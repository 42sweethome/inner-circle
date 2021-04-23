/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:54:02 by junghan           #+#    #+#             */
/*   Updated: 2020/12/27 17:17:15 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	str_len;
	char			*result;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	j = start;
	if (start < str_len)
	{
		while (j < start + len && s[j])
		{
			result[i] = s[j];
			i++;
			j++;
		}
	}
	result[i] = '\0';
	return (result);
}
