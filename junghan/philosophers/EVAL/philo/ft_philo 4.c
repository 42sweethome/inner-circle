/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:45:32 by junghan           #+#    #+#             */
/*   Updated: 2021/07/08 20:31:26 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	time_to_eat(char **av, t_philos *philos, t_info *info)
{
	int	ret;
	int	num;
	int	i;

	ret = ft_atoi(av[1]);
	if (ret < 1)
		return (-1);
	ret = set_malloc(&philos, ret, &num, &info);
	if (ret < 0)
		return (-1);
	ret = check_valid(av, 0, info);
	if (ret < 0)
		return (-1);
	i = -1;
	while (++i < num)
		ret = pthread_mutex_init(&info->forks[i], NULL);
	if (ret != -1)
		ret = have_dining(philos, info);
	if (ret != -1)
		kill_philos(num, philos, info);
	return (ret);
}

int	time_to_eat_limit(char **av, t_philos *philos, t_info *info)
{
	int	ret;
	int	num;
	int	i;

	ret = ft_atoi(av[1]);
	if (ret < 1)
		return (-1);
	ret = set_malloc(&philos, ret, &num, &info);
	if (ret < 0)
		return (-1);
	ret = check_valid(av, 1, info);
	if (ret < 1)
		return (-1);
	i = -1;
	while (++i < num)
		pthread_mutex_init(&info->forks[i], NULL);
	if (ret != -1)
		ret = have_dining(philos, info);
	if (ret != -1)
		kill_philos(num, philos, info);
	return (ret);
}

int	main(int ac, char **av)
{
	int			ret;
	t_philos	*philos;
	t_info		*info;

	if (ac == 5)
		ret = time_to_eat(av, philos, info);
	else if (ac == 6)
		ret = time_to_eat_limit(av, philos, info);
	else
		printf("Please insert the exact number of param. 4 or 5\n");
	if (ret < 0)
		printf("Something wrong!\n");
	return (0);
}
