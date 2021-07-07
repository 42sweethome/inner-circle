/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:02:26 by junghan           #+#    #+#             */
/*   Updated: 2021/07/05 15:41:09 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int			set_malloc(t_philos **philos,int ret, int *num)
{
	int i;

	*num = ret;
	*philos = (t_philos *)malloc(sizeof(t_philos) * (*num));
	if (*philos < 0)
		return (ERROR);
	g_info.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* g_info.num_of_forks);
	//pthread_mutex_init(&(g_info.forks), NULL);
	if (g_info.forks < 0)
		return (ERROR);
//	i = -1;
//	while (++i < g_info.num_of_forks)
//		g_info.forks[i] = 0;
	return (SUCCESS);
}

void		init_philo(t_philos *philos, int index)
{
	philos->starving_time = 0;
	philos->sleeping_time = 0;
	philos->thinking_time = 0;
	philos->left_hand = -1;
	philos->right_hand = -1;
	philos->id = index;
}

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

int			ft_atoi(char *str)
{
	int				i;
	long long int	result;
	long long int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		if (sign < 0 && result > 2147483648)
			return (0);
		else if (sign > 0 && result > 2147483647)
			return (-1);
		i++;
	}
	return ((int)(sign * result));
}
