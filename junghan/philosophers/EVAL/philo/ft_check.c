/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:06:24 by junghan           #+#    #+#             */
/*   Updated: 2021/07/08 20:32:48 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	check_valid(char **av, int limit, t_info *info)
{
	info->time_to_die = ft_atoi(av[2]);
	if (info->time_to_die < 1)
		return (info->time_to_die);
	info->time_to_eat = ft_atoi(av[3]);
	if (info->time_to_eat < 1)
		return (info->time_to_eat);
	info->time_to_sleep = ft_atoi(av[4]);
	if (info->time_to_sleep < 1)
		return (info->time_to_sleep);
	info->limit = 0;
	if (limit)
	{
		info->limit = ft_atoi(av[5]);
		if (info->limit < 1)
			return (info->limit);
	}
	info->num_of_philos = ft_atoi(av[1]);
	info->num_of_forks = info->num_of_philos;
	info->std_time = prst_mili_sec();
	info->die_flag = 1;
	info->check_odd = (info->num_of_philos / 2) + (info->num_of_philos % 2);
	return (info->num_of_philos);
}
