/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 00:58:00 by doyun             #+#    #+#             */
/*   Updated: 2021/02/02 00:35:15 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			intlen(long long int n)
{
	long long int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	char			*num;
	int				len;

	len = intlen(n);
	if (!(num = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	num[len] = '\0';
	if (!n)
		num[0] = '0';
	if (n < 0)
	{
		num[0] = '-';
		if (n == -2147483648)
		{
			num[--len] = '8';
			n = -214748364;
		}
		n *= -1;
	}
	while (n)
	{
		num[--len] = ((n % 10) + '0');
		n /= 10;
	}
	return (num);
}
