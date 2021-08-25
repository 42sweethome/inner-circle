/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:18:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/07 13:39:27 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	pick_up_fork(t_philos *philo)
{
	int left;
	int right;
	while (philo->id % 2 == 0 && g_info.check_odd > 0)
		usleep(50);
//	printf("---here %d ---\n",philo->id );
	if (philo->id % 2 == 1 && g_info.check_odd > 0)
		g_info.check_odd--;
//	printf("pick %d  %lu\n",philo->id ,prst_mili_sec());
//	printf("id %d add %d ---\n",philo->id   , g_info.check_odd );
	left = pthread_mutex_lock(&g_info.forks[(philo->id - 1)]);
	right = pthread_mutex_lock(&g_info.forks[(philo->id % g_info.num_of_forks)]);

//	printf("philo%d ===left %d right %d\n",philo->id, left, right);
//	if (left == 0 && right == 0)
//	{
//		printf("[%lu]	|	philo[%d]	|	picked up BOTH		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
//		return (BOTH);
//	}
	if (left == 0)
		philo->left_hand = 1;
	if (right == 0)
		philo->right_hand = 1;
	if (left != 0 && right != 0)
	{
		printf("[%lu]	|	philo[%d]	|	picked up NONE		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
		return (NONE);
	}
	if (philo->left_hand == 1 && philo->right_hand == 1)
	{
		philo->eat_time++;
		return (BOTH);
	}
	else if (philo->left_hand == 1)
		return (LEFT);
	else
		return (RIGHT);
}

int	eat_to_survive(t_philos *philo)
{
	unsigned long	present;
	int				check;

	present = prst_mili_sec();
	if ((present - philo->starving_time) > g_info.time_to_die)
	{
		philo->die = 1;
		return (FAIL);
	}
	check = pick_up_fork(philo);
	present = prst_mili_sec();
	if (check == LEFT)
	{
		printf("[%lu]	|	philo[%d]	|	picked up LEFT		|\n", (present - g_info.std_time), philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
		philo->left_hand = 0;
		printf("[%lu]	|	philo[%d]	|	picked down LEFT	|\n", (present - g_info.std_time), philo->id);

	}
	else if (check == RIGHT)
	{
		printf("[%lu]	|	philo[%d]	|	picked up RIGHT		|\n", (present - g_info.std_time), philo->id);
		pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
		philo->right_hand = 0;
		printf("[%lu]	|	philo[%d]	|	picked down RIGHT	|\n", (present - g_info.std_time), philo->id);

	}
	else if (check == BOTH)
	{
		printf("[%lu]	|	philo[%d]	|	picked up LEFT		|\n", (present - g_info.std_time), philo->id);
		printf("[%lu]	|	philo[%d]	|	picked up RIGHT		|\n", (present - g_info.std_time), philo->id);
		//philo->starving_time = prst_mili_sec();
		printf("[%lu]	|	philo[%d]	|	eating...[%d]		|\n", (present - g_info.std_time), philo->id, philo->eat_time);
		//printf("num = %d\n",g_info.time_to_eat);
		if (g_info.die_flag == 0)
		{
			philo->die = 1;
			pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
			pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
			return (FAIL);
		}
	//	printf("b_usleep %d,  %lu\n",philo->id , present);
		for_pause(g_info.time_to_eat);
		present = prst_mili_sec();
	//	printf("a_usleep %d,  %lu\n",philo->id,  present);
		if ((present - philo->starving_time) > g_info.time_to_die)
		{
			philo->die = 1;
			pthread_mutex_unlock(&g_info.forks[philo->id - 1]);
			pthread_mutex_unlock(&g_info.forks[philo->id % g_info.num_of_forks]);
			return (FAIL);
		}
		//usleep(20000);
		philo->starving_time = present;
		printf("[%lu]	|	philo[%d]	|	picked down LEFT	|\n", (present - g_info.std_time), philo->id);
		printf("[%lu]	|	philo[%d]	|	picked down RIGHT	|\n", (present - g_info.std_time), philo->id);
		philo->left_hand = 0;
		philo->right_hand = 0;
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
	if (g_info.limit != 0 && g_info.limit == philo->eat_time)
		return (FULL);
	if ((present - philo->starving_time) > g_info.time_to_die)
	{
		philo->die = 1;
		return (FAIL);
	}
	if (check == NONE)
		return (NONE);
	printf("[%lu]	|	philo[%d]	|	sleeping...		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
	if (g_info.die_flag == 0)
		return (FAIL);
	for_pause(g_info.time_to_sleep);
	if ((prst_mili_sec() - philo->starving_time) > g_info.time_to_die)
	{
		philo->die = 1;
		return (FAIL);
	}
	return (SUCCESS);
}

int	think_before_eat(t_philos *philo, int check)
{
	unsigned long	present;

	present = prst_mili_sec();
	if ((present - philo->starving_time) > g_info.time_to_die)
	{
		philo->die = 1;
		return (FAIL);
	}
	printf("[%lu]	|	philo[%d]	|	thinking...		|\n", (prst_mili_sec() - g_info.std_time), philo->id);
	return (SUCCESS);
}
