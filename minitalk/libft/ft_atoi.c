/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:31:57 by sonkang           #+#    #+#             */
/*   Updated: 2021/07/19 23:35:11 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int				i;
	long long int	result;
	long long int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		if (sign < 0 && result > 2147483648)
			return (0);
		else if (sign > 0 && result > 2147483647)
			return (-1);
		i++;
	}
	return ((int)(sign * result));
}
