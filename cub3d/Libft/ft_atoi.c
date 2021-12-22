/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:24:45 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/22 14:34:30 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	flag;
	long long int	res;

	while ((9 <= *str && *str <= 13) || (*str == ' '))
		str++;
	flag = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		flag *= -1;
		str++;
	}
	res = 0;
	while (*str)
	{	
		if (*str < '0' || *str > '9')
			return (-1);
		res = res * 10 + *str - '0';
		if ((flag < 0 && res > 2147483648) || (flag > 0 && res > 2147483647))
			return (-1);
		str++;
	}
	return ((int)(flag * res));
}
