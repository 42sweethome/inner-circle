/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:25:42 by doyun             #+#    #+#             */
/*   Updated: 2021/02/01 22:28:42 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*temp_s;
	unsigned int	len;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(temp_s = (unsigned char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		temp_s[idx] = f(idx, s[idx]);
		idx++;
	}
	temp_s[idx] = '\0';
	return ((char *)temp_s);
}
