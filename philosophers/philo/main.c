/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:23:45 by sonkang           #+#    #+#             */
/*   Updated: 2021/11/23 09:38:30 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*ph_life(void *ph_info)
{
	t_ph	*ph;

	ph = (t_ph *)ph_info;
	ph->last_eat = present(ph);
	if (ph->id % 2 == 0)
		usleep(42);
	while (!ph->die)
	{
		if (ph_eat(ph))
			break ;
		if (ph_sleep(ph))
			break ;
		if (ph_think(ph))
			break ;
	}
	return (NULL);
}

int	birth_philo(t_ph *ph, t_info **info)
{
	int		idx;
	int		check;

	idx = -1;
	check = 0;
	while (++idx < (*info)->ph_num)
	{
		ph[idx].in = *info;
		ph[idx].id = idx + 1;
		ph[idx].eat = 0;
		ph[idx].die = 0;
		check = pthread_create(&ph[idx].thrd, 0, ph_life, &ph[idx]);
		if (check != 0)
		{
			free(*info);
			free(ph);
			return (print_error());
		}
	}
	return (0);
}

int	info_parsing(t_info **info)
{
	int		check;
	int		idx;

	idx = -1;
	check = pthread_mutex_init(&(*info)->ifdie, NULL);
	if (check != 0)
		return (print_error());
	while (++idx < (*info)->ph_num)
	{
		check = pthread_mutex_init(&(*info)->fork[idx], NULL);
		if (check != 0)
			return (print_error());
	}
	gettimeofday(&(*info)->st, NULL);
	(*info)->st_t = (*info)->st.tv_sec * 1000 + (*info)->st.tv_usec / 1000;
	return (0);
}

int	check_argument(char **argv)
{
	int	idx;
	int	jdx;

	idx = 0;
	while (argv[++idx])
	{
		jdx = 0;
		while (argv[idx][jdx])
		{
			if (argv[idx][jdx] < '0' || argv[idx][jdx] > '9')
				return (-1);
			jdx++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			check;
	t_info		*info;
	t_ph		*ph;

	if (argc != 5 && argc != 6)
		return (print_error());
	check = ph_init(argc, argv, &info, &ph);
	if (check == -1)
		return (print_error());
	if (info_parsing(&info))
		return (-1);
	if (birth_philo(ph, &info))
		return (-1);
	check_fin(info, ph);
	return (0);
}
