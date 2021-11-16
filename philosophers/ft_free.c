#include "philo.h"

int	ft_free(t_info *info, t_ph *ph)
{
	int idx;

	idx = -1;
	while(++idx < info->ph_num)
		pthread_mutex_destroy(&info->fork[idx]);
	pthread_mutex_destroy(&info->ifdie);
	free(info);
	free(ph);
	return (0);
}
