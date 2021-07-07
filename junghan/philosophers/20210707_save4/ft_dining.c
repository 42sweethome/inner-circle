/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:50:32 by junghan           #+#    #+#             */
/*   Updated: 2021/07/07 17:49:31 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	full_philos(t_philos *philo)
{
	unsigned long	present;

	present = prst_mili_sec();
	printf("[%lu]	|	philo[%d]	|	is FULL	*^_^*		|\n", \
			(present - g_info.std_time), philo->id);
}

void	starved_philos(t_philos *philo)
{
	unsigned long	present;

	present = prst_mili_sec();
	g_info.die_flag = 0;
	printf("[%lu]	|	philo[%d]	|	is DEAD	0_0		|\n", \
			(present - g_info.std_time), philo->id);
}

void	*acting(void *status)
{
	t_philos		*p_status;
	int				ret;
	unsigned long	present;

	ret = 0;
	present = prst_mili_sec();
	p_status = (t_philos *)status;
	while (g_info.die_flag)
	{
		ret = eat_to_survive(p_status);
		if (ret < 0 || g_info.die_flag == 0)
			break ;
		ret = sleep_after_eat(p_status, ret);
		if (ret < 0 || g_info.die_flag == 0)
			break ;
		ret = think_before_eat(p_status, ret);
		if (ret < 0 || g_info.die_flag == 0)
			break ;
	}
	if (p_status->die)
		starved_philos(p_status);
	else if (g_info.limit == p_status->eat_time)
		full_philos(p_status);
	return (NULL);
}

int	kill_philos(int num, t_philos *philos)
{
	int	i;
	int	ret;
	int	status;

	i = 0;
	while (i < num)
	{
		ret = pthread_join(philos[i].philo, (void *)&status);
		i++;
	}
	free(philos);
	free(g_info.forks);
	return (ret);
}

int	have_dining(t_philos *philos)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < g_info.num_of_philos)
	{
		init_philo(&philos[i], i + 1);
		ret = pthread_create(&philos[i].philo, NULL, acting, \
				(void *)&philos[i]);
		if (ret < 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
