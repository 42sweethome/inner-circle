/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:45:32 by junghan           #+#    #+#             */
/*   Updated: 2021/07/05 15:11:17 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*bring_fork(void *num)
{
	if (g_info.num_of_forks  <= *((int *)num))
		g_info.num_of_forks++;
	printf("Philosopher%d come with fork %d\n", g_info.num_of_forks, g_info.num_of_forks);
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

int		time_to_eat(char **av, t_philos *philos)
{
	int ret;
	int num;
	int i;
	
	ret = check_valid(av, 0);
	if (ret < 0)
		return (ret);
	g_info.num_of_forks = 0;
	philos = (t_philos *)malloc(sizeof(t_philos) * ret);
	num = ret;
	i = 0;
	while (i < num)
	{
		init_philo(&philos[i]);
		ret = pthread_create(&(philos[i].philo), NULL, bring_fork, (void *)&i);
		i++;
	}
	if (ret != -1)
		ret = have_dining(philos);
	if (ret != -1)
		ret = kill_philos(num, philos);
	return (ret);
}


int	time_to_eat_limit(char ** av, t_philos *philos)
{
	int ret;
	int num;
	int i;

	ret = check_valid(av, 1);
	if (ret < 0)
		return (ERROR);
	g_info.num_of_forks = 0;
	ret = set_malloc(&philos, ret, &num);
	if (ret < 0)
		return (ERROR);
	i = 0;
	while (i < num)
	{
		init_philo(&philos[i]);
		ret = pthread_create(&philos[i].philo, NULL, bring_fork, (void *)&i);
		pthread_mutex_init(&g_info.forks[i], NULL);
		i++;
	}
	if (ret != -1)
		ret = have_dining(philos);//ret을 -1 0 1 구분해야함 메모리누수문제
	if (ret != -1)
		kill_philos(num, philos);
	return (ret);
}

int		main(int ac, char **av)
{
	int ret;
	t_philos	*philos;

	if (ac == 5)
		ret = time_to_eat(av, philos);
	else if (ac == 6)
		ret = time_to_eat_limit(av, philos);
	else
		printf("Please insert the exact number of param. 4 or 5\n");
	if (ret < 0)
		printf("Something wlong!\n");
	else //0이면 죽은거?
		printf("The philosophers ard dead\n");
	return (0);
}

