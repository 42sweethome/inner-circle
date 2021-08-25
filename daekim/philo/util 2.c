/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:15:09 by daekim            #+#    #+#             */
/*   Updated: 2021/07/22 13:24:58 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ph->info->num_phi)
		pthread_mutex_destroy(&ph->info->fork[i]);
	free(ph->info->fork);
	free(ph);
}

void	waiting(unsigned int t, t_philo *ph)
{
	unsigned int	st;

	st = now_t();
	while (now_t() - st < t)
	{
		if (ph->info->die == 1 || ph->eat == ph->info->num_eat)
			return ;
		usleep(200);
	}
	return ;
}

unsigned int	now_t(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	check_atoi(char *str, int *i)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (str[a] && ((str[a] >= 9 && str[a] <= 13) || str[a] == ' '))
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			count++;
		a++;
	}
	*i = a;
	return (count);
}

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	long long int	result;

	sign = 1;
	i = 0;
	result = 0;
	if ((check_atoi(str, &i) % 2) != 0)
		sign = -sign;
	while (str[i])
		if (str[i] < '0' || str[i++] > '9')
			return (0);
	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		if ((sign < 0 && result > 2147483648) || \
			(sign > 0 && result > 2147483647))
			return (0);
	}
	result = result * sign;
	return ((int)result);
}
