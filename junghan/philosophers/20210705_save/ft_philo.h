/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:40:29 by junghan           #+#    #+#             */
/*   Updated: 2021/07/05 16:04:44 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H


# define NUM_OF_PHILOS 1
# define TIME_TO_DIE 2
# define TIME_TO_EAT 3
# define TIME_TO_SLEEP 4
# define LIMIT 5
# define DIE 0
# define SUCCESS 0
# define ERROR -1


# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

typedef struct s_philos {
	pthread_t	philo;
	int			starving_time;
	int			sleeping_time;
	int			thinking_time;
	int			left_hand;
	int			right_hand;
	int 		id;
} t_philos;

typedef struct s_info {
	int				num_of_philos;
	int				num_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*forks;
	int				limit;
} t_info;

t_info		g_info;

int			ft_atoi(char *str);
int			set_malloc(t_philos **philos, int ret, int *num);
int			kill_philos(int num, t_philos *philos);
int			have_dining(t_philos *philos);
int			check_valid(char **av, int limit);
void		init_philo(t_philos *philos, int i);

#endif
