#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "./Libft/libft.h"


typedef struct s_ph
{
	pthread_mutex_t	*fork;
	int		thrd;
	struct timeval	born;
	struct timeval	die;
	unsigned int	born_t;
	unsigned int	die_t;
	unsigned int	eat_t;
	unsigned int	sleep_t;
	int		eat_c;
}		t_ph;


#endif
