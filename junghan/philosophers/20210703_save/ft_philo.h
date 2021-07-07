/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:40:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/03 18:12:38 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H


# define NUM_OF_PHILOS 1
# define TIME_TO_DIE 2
# define TIME_TO_EAT 3
# define TIME_TO_SLEEP 4
# define LIMIT 5

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

typedef struct s_philos {
	pthread_t philo;
	int	num_of_meals;
	int	num_of_sleeps;
	int	num_of_thinks;
} t_philos;

typedef struct s_info {
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int limit;
} t_info;

int g_fork;

int			ft_atoi(char *str);
int			check_valid(char **av, int limit, t_info *info);
void		init_philo(t_philos *philos);

#endif
