/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:52:47 by daekim            #+#    #+#             */
/*   Updated: 2021/01/01 22:44:23 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nlen(long long int n)
{
	int				i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char			*num;
	long long int	nu;
	int				a;

	if (n == 0)
		return (ft_strdup("0"));
	nu = n;
	a = nlen(nu);
	if (!(num = (char *)ft_calloc((a + 1), sizeof(char))))
		return (0);
	if (nu < 0)
	{
		nu = -nu;
		num[0] = '-';
	}
	a--;
	while (nu > 0)
	{
		num[a] = (nu % 10) + 48;
		nu = nu / 10;
		a--;
		if (a == 0 && nu > 0)
			num[a] = (nu % 10) + 48;
	}
	return (num);
}
