/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:50:32 by junghan           #+#    #+#             */
/*   Updated: 2021/07/05 15:09:15 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	have_dining(t_philos *philos)
{
	int i;
//	g_info.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* g_info.num_of_forks);

		i = 0;
		while (i < g_info.num_of_philos)
		{
//			pthread_mutex_init(&g_info.forks, NULL);
			if (philos[i].starving_time > g_info.time_to_eat)
				return (DIE);
			i++;
		}
	return (SUCCESS);
}
