/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:37:39 by junghan           #+#    #+#             */
/*   Updated: 2021/07/06 21:32:07 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int			set_malloc(t_philos **philos,int ret, int *num)
{
	int i;

	*num = ret;
	*philos = (t_philos *)malloc(sizeof(t_philos) * (*num));
	if (*philos < 0)
		return (ERROR);
	g_info.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* g_info.num_of_forks);
	if (g_info.forks < 0)
		return (ERROR);
	return (SUCCESS);
}

void		init_philo(t_philos *philos, int index)
{
	philos->starving_time = g_info.std_time;
	philos->sleeping_time = g_info.std_time;
	philos->thinking_time = g_info.std_time;
	philos->left_hand = 0;
	philos->right_hand = 0;
	philos->id = index;
}
