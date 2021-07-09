/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_in_hand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:45:52 by junghan           #+#    #+#             */
/*   Updated: 2021/07/09 11:49:17 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	one_hand_operation(t_philos *philo, int check, \
		unsigned long present, t_info *info)
{
	if (check == 1)
	{
		pthread_mutex_unlock(&info->forks[philo->id - 1]);
		philo->left_hand = 0;
		printf("[%lu]	|	philo[%d]	|	picked down left	|\n", \
				(present - info->std_time), philo->id);
	}
	else if (check == 2)
	{
		pthread_mutex_unlock(&info->forks[philo->id % info->num_of_forks]);
		philo->right_hand = 0;
		printf("[%lu]	|	philo[%d]	|	picked down right	|\n", \
				(present - info->std_time), philo->id);
	}
}

void	set_free_mutex(t_philos *philo, t_info *info)
{
	if (philo->id % 2 == 1)
	{
		printf("[%lu]	|	philo[%d]	|	picked down right	|\n", \
				(prst_mili_sec() - info->std_time), philo->id);
		printf("[%lu]	|	philo[%d]	|	picked down left	|\n", \
				(prst_mili_sec() - info->std_time), philo->id);
		philo->right_hand = 0;
		philo->left_hand = 0;
		pthread_mutex_unlock(&info->forks[philo->id % info->num_of_forks]);
		pthread_mutex_unlock(&info->forks[philo->id - 1]);
	}
	else
	{
		printf("[%lu]	|	philo[%d]	|	picked down left	|\n", \
				(prst_mili_sec() - info->std_time), philo->id);
		printf("[%lu]	|	philo[%d]	|	picked down right	|\n", \
				(prst_mili_sec() - info->std_time), philo->id);
		philo->left_hand = 0;
		philo->right_hand = 0;
		pthread_mutex_unlock(&info->forks[philo->id - 1]);
		pthread_mutex_unlock(&info->forks[philo->id % info->num_of_forks]);
	}
}

int	set_free_hand(t_philos *philo, t_info *info)
{
	unsigned long	present;

	present = prst_mili_sec();
	if (info->die_flag == 0 || (present - philo->starving_time) \
			> info->time_to_die && !(philo->id % 2 == 0 && \
			((present - philo->starving_time) - info->time_to_die < 3)))
	{
		pthread_mutex_unlock(&info->forks[philo->id - 1]);
		pthread_mutex_unlock(&info->forks[philo->id % \
				info->num_of_forks]);
		return (-1);
	}
	set_free_mutex(philo, info);
	philo->starving_time = prst_mili_sec();
	return (0);
}

int	two_hand_operation(t_philos *philo, unsigned long present, t_info *info)
{
	int	ret;

	ret = 3;
	printf("[%lu]	|	philo[%d]	|	eating...[%d]		|\n", \
			(present - info->std_time), philo->id, philo->eat_time);
	if ((info->die_flag == 0 || (present - philo->starving_time) \
			> info->time_to_die))
	{
		philo->die = 1;
		pthread_mutex_unlock(&info->forks[philo->id - 1]);
		pthread_mutex_unlock(&info->forks[philo->id % \
				info->num_of_forks]);
		return (-1);
	}
	for_pause(info->time_to_eat);
	ret = set_free_hand(philo, info);
	if (ret == -1)
	{
		philo->die = 1;
		return (-1);
	}
	return (0);
}
