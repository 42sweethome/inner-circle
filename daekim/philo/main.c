/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:10:31 by daekim            #+#    #+#             */
/*   Updated: 2021/07/21 19:57:07 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_info(char **av, t_info *info)
{
	info->num_phi = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	if (info->num_phi < 2 || info->time_die < 1 || \
		info->time_eat < 1 || info->time_sleep < 1)
		return (0);
	if (av[5])
	{
		info->num_eat = ft_atoi(av[5]);
		if (info->num_eat < 1)
			return (0);
	}
	else if (!av[5])
		info->num_eat = -1;
	return (1);
}

void	init(t_info *info, t_philo *ph)
{
	int	i;

	i = -1;
	info->die = 0;
	info->start = now_t();
	while (++i < info->num_phi)
	{
		pthread_mutex_init(&info->fork[i], NULL);
		ph[i].num = i + 1;
		if (i == 0)
			ph[i].fork1 = info->num_phi - 1;
		else
			ph[i].fork1 = i - 1;
		ph[i].fork2 = i;
		ph[i].eat = 0;
		ph[i].info = info;
	}
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*ph;

	if (!(ac == 5 || ac == 6) || !(get_info(av, &info)))
		return (printf("Arguments Error!"));
	ph = malloc(sizeof(t_philo) * info.num_phi);
	if (!ph)
		return (printf("ph malloc Error!"));
	info.fork = malloc(sizeof(pthread_mutex_t) * info.num_phi);
	if (!info.fork)
		return (printf("Fork malloc Error!"));
	init(&info, ph);
	start_philo(&info, ph);
	free_all(ph);
	return (0);
}
