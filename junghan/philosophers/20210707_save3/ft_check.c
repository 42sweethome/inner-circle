/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:06:24 by junghan           #+#    #+#             */
/*   Updated: 2021/07/07 13:33:01 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int		check_valid(char **av, int limit)
{
	g_info.time_to_die = ft_atoi(av[TIME_TO_DIE]);
	if (g_info.time_to_die < 1)
		return (g_info.time_to_die);
	g_info.time_to_eat = ft_atoi(av[TIME_TO_EAT]);
	if (g_info.time_to_eat < 1)
		return (g_info.time_to_eat);
	g_info.time_to_sleep = ft_atoi(av[TIME_TO_SLEEP]);
	if (g_info.time_to_sleep < 1)
		return (g_info.time_to_sleep);
	g_info.limit = 0;
	if (limit)
	{
		g_info.limit = ft_atoi(av[LIMIT]);
		if (g_info.limit < 1)
			return (g_info.limit);
	}
	g_info.num_of_philos = ft_atoi(av[NUM_OF_PHILOS]);
	g_info.num_of_forks = g_info.num_of_philos;
	g_info.std_time = prst_mili_sec();
	g_info.die_flag = 1;
//	g_info.full_flag = g_info.num_of_philos;
	g_info.check_odd = (g_info.num_of_philos / 2) + (g_info.num_of_philos % 2);
	if (g_info.num_of_philos < 1)
		return (g_info.num_of_philos);
	return (g_info.num_of_philos);
}
