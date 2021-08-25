/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:18:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/06 18:13:42 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	pick_up_fork(t_philos *philo)
{
	int left;
	int right;

	left = pthread_mutex_lock(&g_info.forks[(philo->id - 1)]);
	right = pthread_mutex_lock(&g_info.forks[(philo->id % g_info.num_of_forks)]);

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
	//printf("[eat][%d] pres %lu  time %lu\n",philo->id ,(present - philo->starving_time), g_info.time_to_die);

	if((present - philo->starving_time) > g_info.time_to_die)
		return (FAIL);
	check = pick_up_fork(philo);
	if (check == LEFT)
	{	
		printf("philo [%d] picked down LEFT \n",philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
	//	printf("unlock left %d --\n", check);
	}
	else if (check == RIGHT)
	{
		printf("philo [%d] picked down RIGHT \n",philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
//		printf("unlock right %d --\n", check);

	}
	else if (check == BOTH)
	{
		philo->starving_time = prst_mili_sec();
		printf("philo %d eating...\n", philo->id);


//	printf("id [%d] prst  %lu\n", philo->id, prst_mili_sec());

		usleep(g_info.time_to_eat * 1000);
//	printf("id [%d] prst  %lu\n", philo->id, prst_mili_sec());

//		printf("philo %d am i eat?  pres %lu  time %lu\n",philo->id , (prst_mili_sec() - philo->starving_time), g_info.time_to_die);
		printf("philo [%d] picked down BOTH \n",philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
		pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
	//	printf("unlock left %d --\n", check);
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

	printf("[sleep][%d] pres %lu  time %lu\n",philo->id ,(present - philo->starving_time), g_info.time_to_die);

	printf("philo %d sleeping...\n", philo->id);
	//printf("id [%d] prst  %lu\n", philo->id, prst_mili_sec());
	usleep(g_info.time_to_sleep * 1000);

	//printf("id [%d] prst  %lu\n", philo->id, prst_mili_sec());

	//printf("philo %d am i sleep?  pres %lu  time %lu\n",philo->id ,(prst_mili_sec() - philo->starving_time), g_info.time_to_die);
	return (SUCCESS);
}

int	think_before_eat(t_philos *philo, int check)
{
	unsigned long	present;

	present = prst_mili_sec();
	if ((present - philo->starving_time) > g_info.time_to_die)
		return (FAIL);

	printf("[think][%d] pres %lu  time %lu\n",philo->id ,(prst_mili_sec() - philo->starving_time), g_info.time_to_die);
	//usleep(1000);
	printf("philo %d thinking...\n", philo->id);
	return (SUCCESS);
}
