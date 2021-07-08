/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:37:39 by junghan           #+#    #+#             */
/*   Updated: 2021/07/08 20:33:51 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	set_malloc(t_philos **philos, int ret, int *num, t_info **info)
{
	int	i;

	*num = ret;
	*philos = (t_philos *)malloc(sizeof(t_philos) * (*num));
	if (*philos < 0)
		return (-1);
	*info = (t_info *)malloc(sizeof(t_info));
	if (*info < 0)
		return (-1);
	(*info)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* (*info)->num_of_forks);
	if ((*info)->forks < 0)
		return (-1);
	return (0);
}

void	init_philo(t_philos *philos, int index, t_info *info)
{
	philos->starving_time = info->std_time;
	philos->die = 0;
	philos->full = 0;
	philos->left_hand = 0;
	philos->right_hand = 0;
	philos->eat_time = 0;
	philos->id = index;
	philos->info = info;
}
