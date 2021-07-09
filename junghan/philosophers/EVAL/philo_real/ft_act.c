/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:18:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/09 11:52:29 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	eat_to_survive(t_philos *philo, t_info *info)
{
	int				check;
	int				ret;

	ret = 3;
	if ((info->die_flag == 0 || prst_mili_sec() - philo->starving_time) \
			> info->time_to_die)
	{
		philo->die = 1;
		return (-1);
	}
	check = pick_up_fork(philo, info);
	if (check == 1 || check == 2)
		one_hand_operation(philo, check, prst_mili_sec(), info);
	else if (check == 0)
		ret = two_hand_operation(philo, prst_mili_sec(), info);
	if (ret == -1)
	{
		philo->die = 1;
		return (-1);
	}
	else if (ret == 0)
		return (0);
	else
		return (3);
}

int	sleep_after_eat(t_philos *philo, int check, t_info *info)
{
	if (info->limit != 0 && info->limit == philo->eat_time)
		return (-1);
	if (info->die_flag == 0 || (prst_mili_sec() - philo->starving_time) \
			> info->time_to_die)
	{
		philo->die = 1;
		return (-1);
	}
	if (check == 3)
		return (3);
	printf("[%lu]	|	philo[%d]	|	sleeping...		|\n", \
			(prst_mili_sec() - info->std_time), philo->id);
	if (info->die_flag == 0)
	{
		philo->die = 1;
		return (-1);
	}
	for_pause(info->time_to_sleep);
	if ((prst_mili_sec() - philo->starving_time) > info->time_to_die)
	{
		philo->die = 1;
		return (-1);
	}
	return (0);
}

int	think_before_eat(t_philos *philo, int check, t_info *info)
{
	unsigned long	present;

	present = prst_mili_sec();
	if (info->die_flag == 0 || (present - philo->starving_time) \
			> info->time_to_die)
	{
		philo->die = 1;
		return (-1);
	}
	printf("[%lu]	|	philo[%d]	|	thinking...		|\n", \
			(prst_mili_sec() - info->std_time), philo->id);
	return (0);
}
