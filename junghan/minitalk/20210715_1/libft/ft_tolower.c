/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:28:09 by junghan           #+#    #+#             */
/*   Updated: 2020/12/28 00:21:33 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (65 <= c && c <= 90);
}

int			ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
