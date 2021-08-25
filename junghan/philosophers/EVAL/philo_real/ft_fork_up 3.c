/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:41:48 by junghan           #+#    #+#             */
/*   Updated: 2021/07/09 11:49:47 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	schedule_mutex(t_philos *philo, int *left, int *right, t_info *info)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&info->forks[(philo->id - 1)]);
		printf("[%lu]	|	philo[%d]	|	picked up left		|\n", \
				(prst_mili_sec() - info->std_time), philo->id);
		*left = 1;
		pthread_mutex_lock(&info->forks[(philo->id \
					% info->num_of_forks)]);
		printf("[%lu]	|	philo[%d]	|	picked up right		|\n", \
				(prst_mili_sec() - info->std_time), philo->id);
		*right = 1;
	}
	else if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&info->forks[(philo->id \
					% info->num_of_forks)]);
		printf("[%lu]	|	philo[%d]	|	picked up right		|\n", \
				(prst_mili_sec() - info->std_time), philo->id);
		*right = 1;
		pthread_mutex_lock(&info->forks[(philo->id - 1)]);
		printf("[%lu]	|	philo[%d]	|	picked up left		|\n", \
				(prst_mili_sec() - info->std_time), philo->id);
		*left = 1;
	}
}

void	scheduling(t_philos *philo, int *left, int *right, t_info *info)
{
	while (philo->id % 2 == 0 && info->check_odd > 0)
		usleep(100);
	if (philo->id % 2 == 1 && info->check_odd > 0)
		info->check_odd--;
	schedule_mutex(philo, left, right, info);
	return ;
}

int	pick_up_fork(t_philos *philo, t_info *info)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	scheduling(philo, &left, &right, info);
	if (left == 1)
		philo->left_hand = 1;
	if (right == 1)
		philo->right_hand = 1;
	if (philo->left_hand == 1 && philo->right_hand == 1)
	{
		philo->eat_time++;
		return (0);
	}
	else if (philo->left_hand == 1)
		return (1);
	else if (philo->right_hand == 1)
		return (2);
	return (3);
}
