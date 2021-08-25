/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:18:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/06 17:24:37 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	pick_up_fork(t_philos *philo)
{
	int left;
	int right;

//	printf("philo 1 %d\n",philo->id);

	left = pthread_mutex_lock(&g_info.forks[philo->id]);
//	printf("philo 2 %d\n",(philo->id % g_info.num_of_forks));
	right = pthread_mutex_lock(&g_info.forks[((philo->id + 1) % g_info.num_of_forks)]);
//	printf("philo 3 %d\n",philo->id);

	printf("philo%d left %d right %d\n",philo->id, left, right);
	if (left == 0 && right == 0)
	{
		printf("philo [%d] picked up BOTH \n",philo->id);
		return (BOTH);
	}
	else if (left == 0 && right != 0)
	{
		printf("philo [%d] picked up LEFT \n",philo->id);
		return (LEFT);
	}
	else if (left != 0 && right == 0)
	{	
		printf("philo [%d] picked up RIGHT \n",philo->id);
		return (RIGHT);
	}
	else
	{
		printf("philo [%d] picked up NONE \n",philo->id);
		return (NONE);
	}
}

int	eat_to_survive(t_philos *philo)
{
	unsigned long	present;
	int				check;

	present = prst_mili_sec();
//	printf("present %lu pre-starv %lu\n", present, philo->starving_time);
	if((present - philo->starving_time) > g_info.time_to_eat)
		return (FAIL);
	check = pick_up_fork(philo);
	if (check == LEFT)
	{	
		printf("philo [%d] picked down LEFT \n",philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id]);
	//	printf("unlock left %d --\n", check);
	}
	else if (check == RIGHT)
	{
		printf("philo [%d] picked down RIGHT \n",philo->id);
		pthread_mutex_unlock(&g_info.forks[(philo->id + 1) % g_info.num_of_forks]);
//		printf("unlock right %d --\n", check);

	}
	else if (check == BOTH)
	{
		philo->starving_time = present;
		printf("philo %d eating...\n", philo->id);
		usleep(g_info.time_to_eat * 1000);
		printf("philo [%d] picked down BOTH \n",philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id]);
		pthread_mutex_unlock(&g_info.forks[(philo->id + 1) % g_info.num_of_forks]);
	//	printf("unlock left %d --\n", check);
		return (SUCCESS);
	}
	return (NONE);
}

int	sleep_after_eat(t_philos *philo, int check)
{
	unsigned int	present;

	present = prst_mili_sec();
	if ((present - philo->starving_time) > g_info.time_to_eat)
		return (FAIL);
	if (check == NONE)
		return (NONE);
	printf("philo %d sleeping...\n", philo->id);
	usleep(g_info.time_to_sleep * 1000);
	return (SUCCESS);
}

int	think_before_eat(t_philos *philo, int check)
{
	unsigned int	present;

	present = prst_mili_sec();
	if ((present - philo->starving_time) > g_info.time_to_eat)
		return (FAIL);
	if (check != NONE)
		return (NONE);
	printf("philo %d thinking...\n", philo->id);
	return (SUCCESS);
}
