/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:45:32 by junghan           #+#    #+#             */
/*   Updated: 2021/07/05 16:10:31 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	time_to_eat(char ** av, t_philos *philos)
{
	int ret;
	int num;
	int i;

	ret = check_valid(av, 0);
	if (ret < 0)
		return (ERROR);
	ret = set_malloc(&philos, ret, &num);
	if (ret < 0)
		return (ERROR);
	i = -1;
	while (++i < num)
		ret = pthread_mutex_init(&g_info.forks[i], NULL);
	if (ret != -1)
		ret = have_dining(philos);//ret을 -1 0 1 구분해야함 메모리누수문제
	if (ret != -1)
		kill_philos(num, philos);
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
	ret = set_malloc(&philos, ret, &num);
	if (ret < 0)
		return (ERROR);
	i = -1;
	while (++i < num)
		pthread_mutex_init(&g_info.forks[i], NULL);
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

