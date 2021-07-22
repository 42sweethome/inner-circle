/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:23:33 by daekim            #+#    #+#             */
/*   Updated: 2021/07/22 13:38:16 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die_check(t_philo *ph)
{
	if (ph->info->time_die < now_t() - ph->last_eat || ph->info->die == 1)
	{
		ph->info->die = 1;
		printf("%u : philo[%d] is died\n", \
			now_t() - ph->info->st, ph->id);
		return (1);
	}
	return (0);
}

int	eat(t_philo *ph)
{
	int	id;

	if (die_check(ph))
		return (1);
	id = ph->id;
	pthread_mutex_lock(&ph->info->fork[ph->fork1]);
	pthread_mutex_lock(&ph->info->fork[ph->fork2]);
	printf("%u : philo[%d] has taken forks\n", now_t() - ph->info->st, id);
	printf("%u : philo[%d] eating!    total eat : %d\n", \
		now_t() - ph->info->st, id, ph->eat + 1);
	waiting(ph->info->time_eat, ph);
	pthread_mutex_unlock(&ph->info->fork[ph->fork1]);
	pthread_mutex_unlock(&ph->info->fork[ph->fork2]);
	if (die_check(ph))
		return (1);
	ph->last_eat = now_t();
	ph->eat++;
	if (ph->eat == ph->info->num_eat || ph->info->die == 1)
		return (1);
	return (0);
}

void	*action(void *phi)
{
	t_philo	*ph;

	ph = (t_philo *)phi;
	if (ph->id % 2 == 0)
		usleep(100);
	while (!die_check(ph))
	{
		if (ph->eat == ph->info->num_eat)
			break ;
		if (eat(ph))
			break ;
		if (now_t() - ph->info->st > 1 && ph->info->die == 0)
			printf("%u : philo[%d] sleeping\n", \
				now_t() - ph->info->st, ph->id);
		waiting(ph->info->time_sleep, ph);
		if (die_check(ph))
			return (NULL);
		if (now_t() - ph->info->st > 1 && ph->info->die == 0)
			printf("%u : philo[%d] thinking\n", \
				now_t() - ph->info->st, ph->id);
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
