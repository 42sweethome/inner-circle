/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:18:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/07 18:51:27 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	eat_to_survive(t_philos *philo)
{
	unsigned long	present;
	int				check;
	int				ret;

	ret = NONE;
	if ((prst_mili_sec() - philo->starving_time) > g_info.time_to_die)
	{
		philo->die = 1;
		return (FAIL);
	}
	check = pick_up_fork(philo);
	present = prst_mili_sec();
	if (check == LEFT || check == RIGHT)
		one_hand_operation(philo, check, present);
	else if (check == BOTH)
		ret = two_hand_operation(philo, present);
	if (ret == FAIL)
	{
		philo->die = 1;
		return (FAIL);
	}
	else if (ret == SUCCESS)
		return (SUCCESS);
	else
		return (NONE);
}

int	sleep_after_eat(t_philos *philo, int check)
{
	if (g_info.limit != 0 && g_info.limit == philo->eat_time)
		return (FULL);
	if ((prst_mili_sec() - philo->starving_time) > g_info.time_to_die)
	{
		philo->die = 1;
		return (FAIL);
	}
	if (check == NONE)
		return (NONE);
	printf("[%lu]	|	philo[%d]	|	sleeping...		|\n", \
			(prst_mili_sec() - g_info.std_time), philo->id);
	if (g_info.die_flag == 0)
	{
		philo->die = 1;
		return (FAIL);
	}
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
	printf("[%lu]	|	philo[%d]	|	thinking...		|\n", \
			(prst_mili_sec() - g_info.std_time), philo->id);
	return (SUCCESS);
}
