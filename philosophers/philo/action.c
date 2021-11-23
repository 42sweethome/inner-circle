/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:23:13 by sonkang           #+#    #+#             */
/*   Updated: 2021/11/23 09:37:23 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ph_die(t_ph *ph)
{
	if (present(ph) - ph->last_eat >= ph->in->die_t)
	{
		pthread_mutex_lock(&(ph->in->ifdie));
		if (ph->die == 1)
		{
			pthread_mutex_unlock(&(ph->in->ifdie));
			return (1);
		}
		printf("%u %d died\n", present(ph), ph->id);
		pthread_mutex_unlock(&(ph->in->ifdie));
		ph->die = 1;
		return (1);
	}
	return (0);
}

int	ph_think(t_ph *ph)
{
	pthread_mutex_lock(&(ph->in->ifdie));
	if (ph->die == 1)
	{
		pthread_mutex_unlock(&(ph->in->ifdie));
		return (1);
	}
	printf("%u %d is thinking\n", present(ph), ph->id);
	pthread_mutex_unlock(&(ph->in->ifdie));
	return (0);
}

int	ph_sleep(t_ph *ph)
{
	pthread_mutex_lock(&(ph->in->ifdie));
	if (ph->die == 1)
	{
		pthread_mutex_unlock(&(ph->in->ifdie));
		return (1);
	}
	printf("%u %d is sleeping\n", present(ph), ph->id);
	pthread_mutex_unlock(&(ph->in->ifdie));
	ph->sl_st = present(ph);
	if (doing(ph, ph->in->sleep_t, ph->sl_st))
		return (1);
	return (0);
}

int	fork_mutex(t_ph *ph)
{
	int	fork;

	if (ph->id == ph->in->ph_num)
		fork = 0;
	else
		fork = ph->id;
	pthread_mutex_lock(&(ph->in->fork[ph->id - 1]));
	pthread_mutex_lock(&(ph->in->fork[fork]));
	if (ph_die(ph))
	{
		eatting_mutex_unlock(ph, fork);
		return (1);
	}
	if (print_eatting(ph))
		return (1);
	ph->eat_st = present(ph);
	if (doing(ph, ph->in->eat_t, ph->eat_st))
	{
		eatting_mutex_unlock(ph, fork);
		return (1);
	}
	++ph->eat;
	eatting_mutex_unlock(ph, fork);
	return (0);
}

int	ph_eat(t_ph *ph)
{
	while (ph->in->ph_num == 1)
	{
		if (doing(ph, ph->in->die_t, ph->last_eat) || ph_die(ph))
			return (1);
	}
	if (fork_mutex(ph))
		return (1);
	if (ph_die(ph))
		return (1);
	ph->last_eat = present(ph);
	if (ph->eat == ph->in->eat_c)
		return (1);
	return (0);
}
