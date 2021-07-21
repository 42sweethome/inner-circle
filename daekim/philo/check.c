/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:08:39 by daekim            #+#    #+#             */
/*   Updated: 2021/07/21 20:05:43 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
void	*check_die(void *phi)
{
	t_philo			*ph;
	unsigned int	now;
	int				id;

	ph = phi;
	id = ph->id;
	while (42)
	{
		if (ph->eat == ph->info.num_eat)
			break ;
		now = now_t();
		if (ph->info.time_die < now - ph->last_eat)
		{
			ph->die = 1;
			printf("%u : philo[%d] is died\n", now - ph->info.start, id);
			return (NULL);
		}
	}
	return (NULL);
}*/
