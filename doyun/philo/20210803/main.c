#include "./philo.h"

int	print_error(void)
{
	printf("Error\n");
	return (-1);
}

unsigned int	present(t_ph *ph)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return(now.tv_sec * 1000 + now.tv_usec / 1000 - ph->in->st_t);
}

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

void	doing(t_ph *ph, unsigned int num, unsigned int st)
{
	unsigned int	i;

	i = 0;
	while (42)
	{
		if (present(ph) - ph->last_eat >= ph->in->die_t)
			return ;
		if (st + num <= present(ph))
			return ;
	}
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

int	ph_eat(t_ph *ph)
{
	int	fork;

	if (ph->id == ph->in->ph_num)
		fork = 0;
	else
		fork = ph->id;
	while (ph->in->ph_num == 1)
	{
		doing(ph, ph->in->die_t, ph->last_eat);
		if (ph_die(ph))
			return (1);
	}
	pthread_mutex_lock(&(ph->in->fork[ph->id - 1]));
	pthread_mutex_lock(&(ph->in->fork[fork]));
	printf("time : %u, philo%d has taken a fork\n", present(ph), ph->id);
	if (ph_die(ph))
	{
		pthread_mutex_unlock(&(ph->in->fork[fork]));
		pthread_mutex_unlock(&(ph->in->fork[ph->id - 1]));
		return (1);
	}
	printf("time : %u, philo%d is %d eating\n", present(ph), ph->id, ++ph->eat);
	ph->eat_st = present(ph);
	doing(ph, ph->in->eat_t, ph->eat_st);
	pthread_mutex_unlock(&(ph->in->fork[fork]));
	pthread_mutex_unlock(&(ph->in->fork[ph->id - 1]));
	if (ph_die(ph))
		return (1);
	ph->last_eat = present(ph);
	if (ph->eat == ph->in->eat_c)
		return (1);
	return (0);
}

void	*ph_life(void *ph_info)
{
	t_ph	*ph;
	ph = (t_ph *)ph_info;
	ph->last_eat = present(ph);
	while (42)
	{
		if (ph_eat(ph))
			break ;
		if (ph_sleep(ph))
			break ;
		if (ph_think(ph))
			break ;
	//	if (ph_die(ph))
	//		break ;
	}
	return (NULL);
}

int	ph_init(int argc, char **argv, t_info **info, t_ph **ph)
{
	*info = (t_info *)malloc(sizeof(t_info));
	if ((*info) == NULL)
		return (-1);
	(*info)->ph_num = ft_atoi(argv[1]);
	(*info)->die_t = ft_atoi(argv[2]);
	(*info)->eat_t = ft_atoi(argv[3]);
	(*info)->sleep_t = ft_atoi(argv[4]);
	if (argc == 6)
	{
		(*info)->eat_c = ft_atoi(argv[5]);
		if ((*info)->eat_c <= 0)
			return (-1);
	}
	else
		(*info)->eat_c = -1;
	if ((*info)->ph_num <= 0 || (*info)->die_t <= 0 || (*info)->eat_t <= 0 || (*info)->sleep_t <= 0)
		return (-1);
	(*info)->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (*info)->ph_num);
	*ph = (t_ph *)malloc(sizeof(t_ph) * (*info)->ph_num);
	if ((*info)->fork == NULL || *ph == NULL)
		return (-1);
	return (0);
}

int	check_eatcount(t_ph *ph)
{
	int idx;

	idx = -1;
	while (++idx < ph->in->ph_num)
	{
		if (ph[idx].eat == ph->in->eat_c)
			continue ;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			idx;
	int			check;
	t_info		*info;
	t_ph		*ph;

	if (argc != 5 && argc != 6)
		return (print_error());
	check = ph_init(argc, argv, &info, &ph);
	if (check == -1)
		return (print_error());
	idx = -1;
	while (++idx < info->ph_num)
	{
		check = pthread_mutex_init(&info->fork[idx], NULL);
		if (check != 0)
			return (print_error());
	}
	gettimeofday(&info->st, NULL);
	info->st_t = info->st.tv_sec * 1000 + info->st.tv_usec / 1000; 
	idx = -1;
	while (++idx < info->ph_num)
	{
		ph[idx].in = info;
		ph[idx].id = idx + 1;
		ph[idx].eat = 0;
		ph[idx].die = 0;
		check = pthread_create(&ph[idx].thrd, 0, ph_life, &ph[idx]);
		pthread_detach(ph[idx].thrd);
		if (check != 0)
		{
			idx = -1;
			free(info);
			while(++idx < ft_atoi(argv[1]))
				free(&ph[idx]);
			return (print_error());
		}
	}
	idx = -1;
	while (1)
	{
//		if (ph[++idx].die == 1 || check_eatcount(ph))
//			return (0);
//		 (idx == info->ph_num - 1)
//			idx = -1;
	}
	return (0);
}
