/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:10:50 by daekim            #+#    #+#             */
/*   Updated: 2021/07/22 13:29:57 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int				num_phi;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				num_eat;

	int				die;
	unsigned int	st;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}				t_info;

typedef struct s_philo
{
	int				num;
	int				fork1;
	int				fork2;
	int				eat;
	unsigned int	last_eat;
	int				id;
	pthread_t		th;
	t_info			*info;
}				t_philo;

int				ft_atoi(char *str);
unsigned int	now_t(void);
void			start_philo(t_info *info, t_philo *ph);
void			*check_die(void *phi);
void			waiting(unsigned int t, t_philo *ph);
void			free_all(t_philo *ph);

#endif
