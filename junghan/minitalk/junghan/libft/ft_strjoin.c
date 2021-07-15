/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:24:58 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 16:30:00 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = 1;
	if (!(result = (char *)malloc(sizeof(char) * s1_len + s2_len + 1)))
		return (0);
	ft_strlcpy(result, s1, s1_len + s2_len + 1);
	ft_strlcat(result, s2, s1_len + s2_len + 1);
	return (result);
}
