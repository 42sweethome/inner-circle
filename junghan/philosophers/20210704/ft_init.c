/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:37:39 by junghan           #+#    #+#             */
/*   Updated: 2021/07/07 16:28:11 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	set_malloc(t_philos **philos, int ret, int *num)
{
	int	i;

	*num = ret;
	*philos = (t_philos *)malloc(sizeof(t_philos) * (*num));
	if (*philos < 0)
		return (ERROR);
	g_info.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* g_info.num_of_forks);
	if (g_info.forks < 0)
		return (ERROR);
	g_info.fork_check = (int *)malloc(sizeof(int) \
			* g_info.num_of_forks);
	if (g_info.fork_check < 0)
		return (ERROR);
	return (SUCCESS);
}

void	init_philo(t_philos *philos, int index)
{
	int	i;

	i = -1;
	while (++i < g_info.num_of_forks)
		g_info.fork_check[i] = 0;
	philos->starving_time = g_info.std_time;
	philos->eat_time = 0;
	philos->die = 0;
	philos->full = 0;
	philos->left_hand = 0;
	philos->right_hand = 0;
	philos->id = index;
}
