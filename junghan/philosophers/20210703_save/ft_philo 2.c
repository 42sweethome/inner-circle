/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:45:32 by junghan           #+#    #+#             */
/*   Updated: 2021/07/03 18:13:30 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*bring_fork(void *num)
{
	if (g_fork <= *((int *)num))
		g_fork++;
	printf("Philosopher%d come with fork %d\n", g_fork, g_fork);
	return (NULL);
}

void	kill_philos(int num, t_philos *philos)
{
	int	i;
	int status;

	i = 0;
	while (i < num)
	{
		pthread_join(philos[i].philo, (void *)&status);
		i++;
	}
}

int		time_to_eat(char **av, t_philos *philos, t_info *info)
{
	int ret;
	int num;
	int i;
	
	info = (t_info *)malloc(sizeof(t_info));
	ret = check_valid(av, 0, info);
	if (ret < 0)
		return (ret);
	sleep(1);
	g_fork = 0;
	philos = (t_philos *)malloc(sizeof(t_philos) * ret);
	num = ret;
	i = 0;
	while (i < num)
	{
		init_philo(&philos[i]);
		ret = pthread_create(&(philos[i].philo), NULL, bring_fork, (void *)&i);
		usleep(50);
		i++;
	}
	kill_philos(num, philos);
	return (ret);
}


int	time_to_eat_limit(char ** av, t_philos *philos, t_info *info)
{
	int ret;
	int num;
	int i;

	info = (t_info *)malloc(sizeof(t_info));
	ret = check_valid(av, 1, info);
	if (ret < 0)
		return (ret);
	g_fork = 0;
	philos = (t_philos *)malloc(sizeof(t_philos) * ret);
	num = ret;
	i = 0;
	while (i < num)
	{
		init_philo(&philos[i]);
		ret = pthread_create(&philos[i].philo, NULL, bring_fork, (void *)&i);
		i++;
	}
	kill_philos(num, philos);
	return (ret);
}

int		main(int ac, char **av)
{
	int ret;
	t_philos	*philos;
	t_info		*info;

	if (ac == 5)
		ret = time_to_eat(av, philos, info);
	else if (ac == 6)
		ret = time_to_eat_limit(av, philos, info);
	else
		printf("Please insert the exact number of param. 4 or 5\n");
	if (ret == -1)
		printf("Something wlong!\n");
	else //0이면 죽은거?
		printf("The philosophers ard dead\n");
	return (0);
}

