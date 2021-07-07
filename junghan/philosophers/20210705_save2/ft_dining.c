/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dining.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:50:32 by junghan           #+#    #+#             */
/*   Updated: 2021/07/05 18:03:18 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*acting(void *status)
{
	t_philos		*p_status;
	int				ret;

	ret = 0;
	p_status = (t_philos *)status;
	printf("Philosopher No.%d has entered\n", p_status->id);
	sleep(1);
	printf("%lu\n", prst_mili_sec() - g_info.std_time);
	while (1)
	{
		ret = eat_to_survive(p_status);
		if (ret < 0)
			break;
		ret = sleep_after_eat(p_status);
		if (ret < 0)
			break;
		ret = think_before_eat(p_status);
		if (ret < 0)
			break;
	}
	return (NULL);
}

int		kill_philos(int num, t_philos *philos)
{
	int	i;
	int ret;
	int status;

	i = 0;
	while (i < num)
	{
		ret = pthread_join(philos[i].philo, (void *)&status);
		i++;
	}
	return (ret);
}

int		have_dining(t_philos *philos)
{
	int i;
	int ret;
	//	g_info.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* g_info.num_of_forks);
	i = 1;
	ret = 0;
	while (i <= g_info.num_of_philos)
	{
		init_philo(&philos[i], i);
		ret = pthread_create(&philos[i].philo, NULL, acting, (void *)&philos[i]);
		if (ret < 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}


