/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:49:24 by doyun             #+#    #+#             */
/*   Updated: 2021/06/11 20:28:47 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int				ft_memchr(int *s, int c, size_t n)
{
	int	*temp_s;

	temp_s = s;
	while (n)
	{
		if (*(++temp_s) == c)
			return (1);
		n--;
	}
	return (0);
}
