/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 00:58:00 by doyun             #+#    #+#             */
/*   Updated: 2021/08/01 18:11:38 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long long int n)
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

void	miner_int(int *n, int *len,char **num)
{
	(*num)[0] = '-';
	if (*n == -2147483648)
	{
		(*num)[--(*len)] = '8';
		*n = -214748364;
	}
	*n *= -1;
}

char	*ft_itoa(int n)
{
	char			*num;
	int				len;

	len = intlen(n);
	num = (char *)malloc(sizeof(char) * len + 1);
	if (!num)
		return (0);
	num[len] = '\0';
	if (!n)
		num[0] = '0';
	if (n < 0)
		miner_int(&n, &len, &num);
	while (n)
	{
		num[--len] = ((n % 10) + '0');
		n /= 10;
	}
	return (num);
}
