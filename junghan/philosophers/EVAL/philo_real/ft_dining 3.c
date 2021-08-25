/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:50:32 by junghan           #+#    #+#             */
/*   Updated: 2021/07/09 11:12:48 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	full_philos(t_philos *philo, t_info *info)
{
	unsigned long	present;

	present = prst_mili_sec();
	printf("[%lu]	|	philo[%d]	|	is full	d_d		|\n", \
			(present - info->std_time), philo->id);
}

void	starved_philos(t_philos *philo, t_info *info)
{
	unsigned long	present;

	present = prst_mili_sec();
	info->die_flag = 0;
	printf("[%lu]	|	philo[%d]	|	is dead	0_0		|\n", \
			(present - info->std_time), philo->id);
}

void	*acting(void *status)
{
	t_philos		*p_status;
	int				ret;

	p_status = (t_philos *)status;
	if (p_status->info->num_of_philos <= 1)
		p_status->info->die_flag = 0;
	while (p_status->info->die_flag)
	{
		ret = eat_to_survive(p_status, p_status->info);
		if (ret < 0 || p_status->info->die_flag == 0)
			break ;
		ret = sleep_after_eat(p_status, ret, p_status->info);
		if (ret < 0 || p_status->info->die_flag == 0)
			break ;
		ret = think_before_eat(p_status, ret, p_status->info);
		if (ret < 0 || p_status->info->die_flag == 0)
			break ;
	}
	if (p_status->info->die_flag == 0)
		p_status->die = 1;
	if (p_status->die)
		starved_philos(p_status, p_status->info);
	else if (p_status->info->limit == p_status->eat_time)
		full_philos(p_status, p_status->info);
	return (NULL);
}

int	kill_philos(int num, t_philos *philos, t_info *info)
{
	int	i;
	int	ret;
	int	status;

	i = 0;
	while (i < num)
	{
		ret = pthread_join(philos[i].philo, (void *)&status);
		if (ret < 0)
			return (-1);
		ret = pthread_mutex_destroy(&(info->forks[i]));
		i++;
	}
	free(philos);
	free(info->forks);
	free(info);
	return (ret);
}

int	have_dining(t_philos *philos, t_info *info)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < info->num_of_philos)
	{
		init_philo(&philos[i], i + 1, info);
		ret = pthread_create(&philos[i].philo, NULL, acting, \
				(void *)&philos[i]);
		if (ret < 0)
			return (-1);
		i++;
	}
	return (0);
}
