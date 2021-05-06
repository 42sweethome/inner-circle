/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:21:38 by junghan           #+#    #+#             */
/*   Updated: 2020/12/24 01:47:31 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)s;
	while (n > 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
	return ;
}
