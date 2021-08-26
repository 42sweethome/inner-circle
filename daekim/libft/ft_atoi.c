/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 09:10:01 by daekim            #+#    #+#             */
/*   Updated: 2021/01/01 22:42:58 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check(const char *str, int *i)
{
	int				a;
	int				count;

	a = 0;
	count = 0;
	while (str[a] && ((str[a] >= 9 && str[a] <= 13) || str[a] == ' '))
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			count++;
		a++;
	}
	*i = a;
	return (count);
}

int					ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

	sign = 1;
	i = 0;
	result = 0;
	if ((check(str, &i) % 2) != 0)
		sign = -sign;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
		if (sign < 0 && result > 2147483648)
			return (0);
		else if (sign > 0 && result > 2147483647)
			return (-1);
	}
	result = result * sign;
	return (result);
}
