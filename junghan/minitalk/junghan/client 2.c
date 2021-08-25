/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 18:01:00 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli.h"

void	change_base(int pid, int ch)
{
	int jdx;
	int ret;
	unsigned char filter;

	filter = 0x80; //1000 0000
	jdx = -1;
	while (++jdx < 8)
	{
		if (ch & filter)
			kill(pid, SIGUSR1); //1일때
		else
			kill(pid, SIGUSR2); //0일때
		filter = filter >> 1;
		usleep(190);
	}
}

void	check(int signo)
{
	write(1, "GOT IT\n", 7);
}

unsigned long	prst_mili_sec(void)
{
	struct timeval	time;
	unsigned long	ms;

	gettimeofday(&time, NULL);
	ms = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (ms);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	my;
	int	idx;
	char	*str;
	struct sigaction	new_tmp;
	unsigned long		basetime;

	basetime = prst_mili_sec();
	new_tmp.sa_handler = check;

	sigaction(SIGUSR1, &new_tmp, 0);

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = ft_strdup(argv[2]);

		idx = -1;
		while (str[++idx])
			change_base(pid, str[idx]);
		change_base(pid, 0);
		my = getpid();
		str = ft_itoa(my);
		idx = -1;
		while (str[++idx])
			change_base(pid, str[idx]);
		change_base(pid, 0);
	}
	else
		write(1, "arg error\n", 10);

	printf("how many %lu\n", (prst_mili_sec() - basetime));
	return (0);
}
