#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "./Libft/libft.h"

typedef struct s_info
{
	pthread_mutex_t	*fork;
	int				ph_num;
	struct timeval	st;
	unsigned int	st_t;
	unsigned int	die_t;
	unsigned int	eat_t;
	unsigned int	sleep_t;
	int				eat_c;
}		t_info;

typedef struct s_ph
{
	pthread_t		thrd;
	unsigned int	last_eat;
	unsigned int	eat_st;
	unsigned int	sl_st;
	int				id;
	int				eat;
	int				die;
	t_info			*in;
}		t_ph;

#endif
