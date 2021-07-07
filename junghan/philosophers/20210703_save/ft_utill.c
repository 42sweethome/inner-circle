/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:02:26 by junghan           #+#    #+#             */
/*   Updated: 2021/07/03 18:12:27 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void		init_philo(t_philos *philos)
{
	philos->num_of_meals = 0;
	philos->num_of_sleeps = 0;
	philos->num_of_thinks = 0;
}

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

int			ft_atoi(char *str)
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
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
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
