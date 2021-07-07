/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:06:24 by junghan           #+#    #+#             */
/*   Updated: 2021/07/03 18:10:46 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int		check_valid(char **av, int limit, t_info *info)
{
	info->time_to_die = ft_atoi(av[TIME_TO_DIE]);
	if (info->time_to_die < 1)
		return (info->time_to_die);
	info->time_to_eat = ft_atoi(av[TIME_TO_EAT]);
	if (info->time_to_eat < 1)
		return (info->time_to_eat);
	info->time_to_sleep = ft_atoi(av[TIME_TO_SLEEP]);
	if (info->time_to_sleep < 1)
		return (info->time_to_sleep);
	if (limit)
	{
		info->limit = ft_atoi(av[LIMIT]);
		if (info->limit < 1)
			return (info->limit);
	}
	info->num_of_philos = ft_atoi(av[NUM_OF_PHILOS]);
	if (info->num_of_philos < 1)
		return (info->num_of_philos);
	return (info->num_of_philos);
}
