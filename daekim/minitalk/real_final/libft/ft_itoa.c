/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 21:58:36 by sonkang           #+#    #+#             */
/*   Updated: 2021/07/19 23:32:52 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countpos(long long int tmp, int *sign)
{
	int	ans;

	ans = 0;
	if (tmp < 0)
	{
		(*sign) *= -1;
		tmp *= -1;
		ans++;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		ans++;
	}
	ans++;
	return (ans);
}

char	*ft_itoa(int n)
{
	long long int	tmp;
	int				digit_pos;
	char			*result;
	int				sign;

	sign = 1;
	tmp = (long long int)n;
	digit_pos = ft_countpos(tmp, &sign);
	result = (char *)ft_calloc(digit_pos + 1, sizeof(char));
	if (result == 0)
		return (0);
	if (sign < 0)
		tmp *= sign;
	digit_pos--;
	while (digit_pos >= 0)
	{
		result[digit_pos] = tmp % 10 + '0';
		tmp /= 10;
		digit_pos--;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
