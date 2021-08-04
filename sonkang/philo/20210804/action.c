#include "./philo.h"

int	ph_die(t_ph *ph)
{
	if (present(ph) - ph->last_eat >= ph->in->die_t)
	{
		printf("time : %u, philo%d is died\n", present(ph), ph->id);
		ph->die = 1;
		return (1);
	}
	return (0);
}

int	ph_think(t_ph *ph)
{
	printf("time : %u, philo%d is thinking\n", present(ph), ph->id);
	return (0);
}

int	ph_sleep(t_ph *ph)
{
	printf("time : %u, philo%d is sleeping\n", present(ph), ph->id);
	ph->sl_st = present(ph);
	doing(ph, ph->in->sleep_t, ph->sl_st);
	if (ph_die(ph))
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
		pthread_mutex_unlock(&(ph->in->fork[fork]));
		pthread_mutex_unlock(&(ph->in->fork[ph->id - 1]));
		return (1);
	}
	printf("time : %u, philo%d has taken a fork\n", present(ph), ph->id);
	printf("time : %u, philo%d is %d eating\n", present(ph), ph->id, ++ph->eat);
	ph->eat_st = present(ph);
	doing(ph, ph->in->eat_t, ph->eat_st);
	pthread_mutex_unlock(&(ph->in->fork[fork]));
	pthread_mutex_unlock(&(ph->in->fork[ph->id - 1]));
	return (0);
}

int	ph_eat(t_ph *ph)
{
	while (ph->in->ph_num == 1)
	{
		doing(ph, ph->in->die_t, ph->last_eat);
		if (ph_die(ph))
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
