#include "./philo.h"

void	*ph_life(void *ph_info)
{
	t_ph	*ph;

	ph = (t_ph *)ph_info;
	ph->last_eat = present(ph);
	if (ph->id % 2 == 0)
		usleep(42);
	while (42)
	{
		if (ph_eat(ph))
			break ;
		if (ph_sleep(ph))
			break ;
		if (ph_think(ph))
			break ;
	}
	return (NULL);
}

int	birth_philo(t_ph *ph, t_info **info, char *argv)
{
	int		idx;
	int		check;

	idx = -1;
	check = 0;
	while (++idx < (*info)->ph_num)
	{
		ph[idx].in = *info;
		ph[idx].id = idx + 1;
		ph[idx].eat = 0;
		ph[idx].die = 0;
		check = pthread_create(&ph[idx].thrd, 0, ph_life, &ph[idx]);
		pthread_detach(ph[idx].thrd);
		if (check != 0)
		{
			idx = -1;
			free(*info);
			while(++idx < ft_atoi(argv))
				free(&ph[idx]);
			return (print_error());
		}
	}
	return (0);
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
if (birth_philo(ph, &info, argv[1]))
		return (-1);
	idx = -1;
	while (1)
	{
		if (ph[++idx].die == 1 || check_eatcount(ph))
			break ;
		if (idx == info->ph_num - 1)
			idx = -1;
	}
		return (0);
}
