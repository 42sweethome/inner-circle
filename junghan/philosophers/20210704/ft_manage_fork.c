/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:41:48 by junghan           #+#    #+#             */
/*   Updated: 2021/07/07 16:48:00 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	pick_up_fork(t_philos *philo)
{
	int	left;
	int	right;

//	while (philo->id % 2 == 0 && g_info.check_odd > 0)
//		usleep(50);
//	if (philo->id % 2 == 1 && g_info.check_odd > 0)
//		g_info.check_odd--;
	if (philo->id % 2 == 1)
	{
		if (g_info.fork_check[philo->id - 1] == 0)
		{
			left = pthread_mutex_lock(&g_info.forks[(philo->id - 1)]);
			g_info.fork_check[philo->id - 1] = 1;
		}
		if (g_info.fork_check[philo->id % g_info.num_of_forks] == 0)
		{
			right = pthread_mutex_lock(&g_info.forks[(philo->id \
					% g_info.num_of_forks)]);
			g_info.fork_check[philo->id % g_info.num_of_forks] = 1;
		}
	}
	else if (philo->id % 2 == 0)
	{
		if (g_info.fork_check[philo->id % g_info.num_of_forks] == 0)
		{
			right = pthread_mutex_lock(&g_info.forks[(philo->id \
					% g_info.num_of_forks)]);
			g_info.fork_check[philo->id % g_info.num_of_forks] = 1;
		}
		if (g_info.fork_check[philo->id - 1] == 0)
		{
			left = pthread_mutex_lock(&g_info.forks[(philo->id - 1)]);
			g_info.fork_check[philo->id - 1] = 1;
		}
	}
	if (left == 0)
		philo->left_hand = 1;
	if (right == 0)
		philo->right_hand = 1;
	if (philo->left_hand == 1 && philo->right_hand == 1)
	{
		philo->eat_time++;
		return (BOTH);
	}
	else if (philo->left_hand == 1 &&  philo->right_hand == 0)
		return (LEFT);
	else if (philo->right_hand == 1 &&  philo->left_hand == 0)
		return (RIGHT);
	return (NONE);
}

void	one_hand_operation(t_philos *philo, int check, unsigned long present)
{
	if (check == LEFT)
	{
		printf("[%lu]	|	philo[%d]	|	picked up LEFT		|\n", \
				(present - g_info.std_time), philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
		philo->left_hand = 0;
		g_info.fork_check[philo->id - 1] = 0;
		printf("[%lu]	|	philo[%d]	|	picked down LEFT	|\n", \
				(present - g_info.std_time), philo->id);
	}
	else if (check == RIGHT)
	{
		printf("[%lu]	|	philo[%d]	|	picked up RIGHT		|\n", \
				(present - g_info.std_time), philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
		philo->right_hand = 0;
		printf("[%lu]	|	philo[%d]	|	picked down RIGHT	|\n", \
				(present - g_info.std_time), philo->id);
		g_info.fork_check[philo->id % g_info.num_of_forks] = 0;
	}
}

int	set_free_hand(t_philos *philo)
{
	unsigned long	present;

	present = prst_mili_sec();
	if ((present - philo->starving_time) > g_info.time_to_die)
	{
		philo->die = 1;
		pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
		pthread_mutex_unlock(&g_info.forks[philo->id % \
				g_info.num_of_forks]);
		return (FAIL);
	}
	philo->starving_time = present;
	printf("[%lu]	|	philo[%d]	|	picked down LEFT	|\n", \
			(present - g_info.std_time), philo->id);
	g_info.fork_check[philo->id - 1] = 0;
	printf("[%lu]	|	philo[%d]	|	picked down RIGHT	|\n", \
			(present - g_info.std_time), philo->id);
	g_info.fork_check[philo->id % g_info.num_of_forks] = 0;
	philo->left_hand = 0;
	philo->right_hand = 0;
	pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
	pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
	return (SUCCESS);
}

int	two_hand_operation(t_philos *philo, unsigned long present)
{
	int	ret;

	ret = NONE;
	if (philo->id % 2 == 1)
	{
		printf("[%lu]	|	philo[%d]	|	picked up LEFT		|\n", \
			(present - g_info.std_time), philo->id);
		printf("[%lu]	|	philo[%d]	|	picked up RIGHT		|\n", \
			(present - g_info.std_time), philo->id);
	}
	else
	{
		printf("[%lu]	|	philo[%d]	|	picked up RIGHT		|\n", \
			(present - g_info.std_time), philo->id);
		printf("[%lu]	|	philo[%d]	|	picked up LEFT		|\n", \
			(present - g_info.std_time), philo->id);
	}
	printf("[%lu]	|	philo[%d]	|	eating...[%d]		|\n", \
			(present - g_info.std_time), philo->id, philo->eat_time);
	if (g_info.die_flag == 0 || (present - philo->starving_time) \
			> g_info.time_to_die)
	{
		philo->die = 1;
		pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
		pthread_mutex_unlock(&g_info.forks[philo->id % \
				g_info.num_of_forks]);
		return (FAIL);
	}
	for_pause(g_info.time_to_eat);
	ret = set_free_hand(philo);
	if (ret == FAIL)
		return (FAIL);
	return (SUCCESS);
}
