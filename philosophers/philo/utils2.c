/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:23:37 by sonkang           #+#    #+#             */
/*   Updated: 2021/11/23 09:37:48 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_info *info, t_ph *ph)
{
	int	idx;
	int	result;

	idx = -1;
	while (++idx < info->ph_num)
		pthread_join(ph[idx].thrd, (void *)&result);
	idx = -1;
	while (++idx < info->ph_num)
		pthread_mutex_destroy(&info->fork[idx]);
	pthread_mutex_destroy(&info->ifdie);
	free(info->fork);
	free(info);
	free(ph);
}

void	check_fin(t_info *info, t_ph *ph)
{
	int	idx;

	idx = -1;
	while (1)
	{
		if (ph[++idx].die == 1 || check_eatcount(ph))
		{
			idx = -1;
			while (++idx < info->ph_num)
				ph[idx].die = 1;
			ft_free(info, ph);
			return ;
		}
		if (idx == info->ph_num - 1)
			idx = -1;
	}
}

int	print_eatting(t_ph *ph)
{
	pthread_mutex_lock(&(ph->in->ifdie));
	if (ph->die == 1)
	{
		pthread_mutex_unlock(&(ph->in->ifdie));
		return (1);
	}
	printf("%u %d has taken a fork\n", present(ph), ph->id);
	printf("%u %d is eating\n", present(ph), ph->id);
	pthread_mutex_unlock(&(ph->in->ifdie));
	return (0);
}

void	eatting_mutex_unlock(t_ph *ph, int fork)
{
	pthread_mutex_unlock(&(ph->in->fork[fork]));
	pthread_mutex_unlock(&(ph->in->fork[ph->id - 1]));
}
