/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:23:33 by daekim            #+#    #+#             */
/*   Updated: 2021/07/21 20:14:43 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	eat(t_philo *ph)
{
	unsigned int	now;
	int				id;

	if (ph->info.die == 1)
		return (1);
	id = ph->id;
	pthread_mutex_lock(&ph->info.fork[ph->fork1]);
	pthread_mutex_lock(&ph->info.fork[ph->fork2]);
	now = now_t();
	printf("%u : philo[%d] has taken forks\n", now - ph->info.start, id);
	printf("%u : philo[%d] eating! total : %d\n", now - ph->info.start, id, ph->eat + 1);
	waiting(ph->info.time_eat);
	pthread_mutex_unlock(&ph->info.fork[ph->fork1]);
	pthread_mutex_unlock(&ph->info.fork[ph->fork2]);
	if (ph->info.time_die < now_t() - ph->last_eat)
	{
		ph->info.die = 1;
		printf("%u : philo[%d] is died\n", now_t() - ph->info.start, ph->id);
		return (1);
	}
	ph->last_eat = now_t();
	ph->eat++;
	if (ph->eat == ph->info.num_eat)
	{
		ph->info.eat++;
		return (1);
	}
	return (0);
}

void	*action(void *phi)
{
	t_philo			*ph;
	pthread_t		th;
	unsigned int	now;

	ph = (t_philo *)phi;
	if (ph->id % 2 == 0)
		usleep(100);
	while (!ph->info.die)
	{
		if (ph->eat == ph->info.num_eat || ph->info.die == 1)
			break ;
		if (eat(ph))
			break ;
if (now - ph->info.start > 1 && ph->info.die == 0)
		printf("%u : philo[%d] sleeping\n", now_t() - ph->info.start, ph->id);
		waiting(ph->info.time_sleep);
	if (ph->info.time_die < now_t() - ph->last_eat)
		{
			ph->info.die = 1;
			printf("%u : philo[%d] is died\n", now_t() - ph->info.start, ph->id);
			return (NULL);
		}

if (now - ph->info.start > 1 && ph->info.die == 0)
		printf("%u : philo[%d] thinking\n", now_t() - ph->info.start, ph->id);
}
	return (NULL);
}

void	start_philo(t_info *info, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < info->num_phi)
	{
		ph[i].last_eat = now_t();
		ph[i].id = i + 1;
		if (0 < pthread_create(&ph[i].th, NULL, action, &ph[i]))
			return ;
	}
	i = -1;
	while (++i < info->num_phi)
		pthread_join(ph[i].th, NULL);
}
