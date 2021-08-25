/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:18:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/06 21:18:49 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	pick_up_fork(t_philos *philo)
{
	int left;
	int right;
//	unsigned long	present;

//	present = prst_mili_sec();
//	printf("philo%d =left %d right %d\n",philo->id, left, right);

	//left = pthread_mutex_lock(&g_info.forks[(philo->id - 1)]);
	//printf("philo%d ==left %d right %d\n",philo->id, left, right);

	left = pthread_mutex_lock(&g_info.forks[(philo->id - 1)]);
	right = pthread_mutex_lock(&g_info.forks[(philo->id % g_info.num_of_forks)]);

//	printf("philo%d ===left %d right %d\n",philo->id, left, right);
	if (left == 0 && right == 0)
	{
		printf("[%lu]	|	philo[%d]	|	picked up BOTH		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		return (BOTH);
	}
	else if (left == 0 && right != 0)
	{
		printf("[%lu]	|	philo[%d]	|	picked up LEFT		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		return (LEFT);
	}
	else if (left != 0 && right == 0)
	{	
		printf("[%lu]	|	philo[%d]	|	picked up RIGHT		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		return (RIGHT);
	}
	else
	{
		printf("[%lu]	|	philo[%d]	|	picked up NONE		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		return (NONE);
	}
}

int	eat_to_survive(t_philos *philo)
{
	unsigned long	present;
	int				check;

	present = prst_mili_sec();
	if((present - philo->starving_time) > g_info.time_to_die)
		return (FAIL);
	check = pick_up_fork(philo);
	if (check == LEFT)
	{	
		printf("[%lu]	|	philo[%d]	|	picked down LEFT	|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
	}
	else if (check == RIGHT)
	{
		printf("[%lu]	|	philo[%d]	|	picked down RIGHT	|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);

	}
	else if (check == BOTH)
	{
	//	philo->starving_time = prst_mili_sec();
		printf("[%lu]	|	philo[%d]	|	eating...		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		//printf("num = %d\n",g_info.time_to_eat);
		usleep(g_info.time_to_eat * 1000);
		if ((prst_mili_sec() - philo->starving_time) > g_info.time_to_die)
		{
			pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
			pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
			return (FAIL);
		}
		//usleep(20000);
		philo->starving_time = prst_mili_sec();

		printf("[%lu]	|	philo[%d]	|	picked down BOTH	|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
		pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
		return (SUCCESS);
	}
	return (NONE);
}

int	sleep_after_eat(t_philos *philo, int check)
{
	unsigned long	present;
	present = prst_mili_sec();
	if ((present - philo->starving_time) > g_info.time_to_die)
		return (FAIL);
	if (check == NONE)
		return (NONE);
	printf("[%lu]	|	philo[%d]	|	sleeping...		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
	usleep(g_info.time_to_sleep * 1000);
	if ((prst_mili_sec() - philo->starving_time) > g_info.time_to_die)
		return (FAIL);
	return (SUCCESS);
}

int	think_before_eat(t_philos *philo, int check)
{
	unsigned long	present;

	present = prst_mili_sec();
	if ((present - philo->starving_time) > g_info.time_to_die)
		return (FAIL);
	printf("[%lu]	|	philo[%d]	|	thinking...		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
	return (SUCCESS);
}
