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
	pthread_mutex_t	ifdie;
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

int				print_error(void);
unsigned int	present(t_ph *ph);
int				ph_die(t_ph *ph);
void			doing(t_ph *ph, unsigned int num, unsigned int st);
int				ph_think(t_ph *ph);
int				ph_sleep(t_ph *ph);
int				ph_eat(t_ph *ph);
int				ph_init(int argc, char **argv, t_info **info, t_ph **ph);
int				check_eatcount(t_ph *ph);

#endif
