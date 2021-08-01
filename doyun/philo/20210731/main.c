#include "./philo.h"

int	print_error(void)
{
	printf("Error\n");
	return (-1);
}

/*int	eat()
{

}
*/

void	*ph_life(void *info)
{
	t_ph *ph = info;
	printf("start thread %d %d\n",ph->thrd, ((t_ph *)info)->thrd);
	gettimeofday(&ph->born, NULL);
	ph->born_t = ph->born.tv_sec * 1000 + ph->born.tv_usec / 1000;
	usleep(200 * 1000);
	printf("%u %ld\n", ph->born_t, ph->die.tv_sec * 1000 + ph->die.tv_usec / 1000);
	gettimeofday(&ph->die, NULL);
	if (ph->die.tv_sec * 1000 + ph->die.tv_usec / 1000 >= ph->born_t + ph->die_t)
		printf("%ld %d died\n",ph->die.tv_sec * 1000 + ph->die.tv_usec / 1000, ph->thrd);
	return (NULL);
}

int	main(int argc, char **argv)//철학자 수, 죽는시간, 먹는시간, 자는시간, 먹는 횟수
{
	pthread_t	*p_thrd;
	int			num_ph;
	int			check;
	t_ph		*ph;

	if (argc != 5 && argc != 6)
		return (print_error());
	ph = (t_ph *)malloc(sizeof(t_ph));
	ph->thrd = -1;
	num_ph = ft_atoi(argv[1]);//atoi 에서 리턴 값 확인하고 들어오는값 확인하여 예외처리
	ph->die_t = ft_atoi(argv[2]);
	ph->eat_t = ft_atoi(argv[3]);
	ph->sleep_t = ft_atoi(argv[4]);
	if (argc == 6)
		ph->eat_c = ft_atoi(argv[5]);
	p_thrd = (pthread_t *)malloc(sizeof(pthread_t) * num_ph);
	ph->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_ph);
	if (p_thrd == NULL || ph->fork == NULL)
		return (print_error());
	while (++ph->thrd < num_ph)
	{
		check = pthread_mutex_init(&ph->fork[ph->thrd], NULL);
		if (check != 0)
			return (print_error());
	}
	ph->thrd = -1;
	while (++ph->thrd < num_ph)
	{
		check = pthread_create(&p_thrd[ph->thrd], 0, ph_life, ph);
		if (check != 0)
		{
			free(ph);
			return (print_error());
		}
	}
	ph->thrd = -1;
	while (++(ph->thrd) < num_ph)
	{
		printf("%d\n", ph->thrd);
		pthread_join((p_thrd[ph->thrd]), NULL);
	}
	return (0);
}
