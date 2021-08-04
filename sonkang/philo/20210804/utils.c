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
