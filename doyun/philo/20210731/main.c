#include "./philo.h"

int	print_error(void)
{
	printf("Error\n");
	return (-1);
}

int	sleep(t_ph *ph)
{
	
}

int	eat(t_ph *ph)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	pthread_mutex_lock(&(ph->fork[ph->thrd]));
	//left right 1로 바꿔서  식사하기
	//eat_t끝나면 공유자원 0으로 초기화하고 unlock
	pthread_mutex_unlock(&(ph->fork[ph->thrd]));
	//자러가기 sleep();
}


void	*ph_life(void *info)
{
	//살아난 시간 측정하기
	//스레드안에서 gettimeofday는 각자 따로 돌것이기 때문에
	//각각의 스레드에서공복시간(현재 시스템 시간 - 살아난 시간) 확인하면서 
	//먹은 직후에 살아난시간을 그때 시스템시간으로 초기화하면 될듯
	t_ph *ph = info;
	printf("start thread %d %d\n",ph->thrd, ((t_ph *)info)->thrd);
	gettimeofday(&ph->born, NULL);
	ph->born_t = ph->born.tv_sec * 1000 + ph->born.tv_usec / 1000;
	printf("tv_sec %ld tv_usec %d\n",ph->born.tv_sec * 1000, ph->born.tv_usec);
	usleep(3 * 1000 * 1000);
	printf("born_t : %u s+u : %ld\n", ph->born_t, ph->die.tv_sec * 1000 + ph->die.tv_usec / 1000);
	gettimeofday(&ph->die, NULL);
	if (ph->die.tv_sec * 1000 + ph->die.tv_usec / 1000 >= ph->born_t + ph->die_t)
		printf("%ld %d died\n",ph->die.tv_sec * 1000 + ph->die.tv_usec / 1000, ph->thrd);
	printf("born_t : %u s+u : %ld\n", ph->born_t, ph->die.tv_sec * 1000 + ph->die.tv_usec / 1000);
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
	ph->thrd = -1;	//몇번째 thread인지 알기위함
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
	while (++ph->thrd < num_ph) //철학자 수만큼 thread 생성
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
		printf("before join : thread %d\n", ph->thrd);
		pthread_join((p_thrd[ph->thrd]), NULL);
		printf("after join : thread %d\n", ph->thrd);
	}
	return (0);
}
