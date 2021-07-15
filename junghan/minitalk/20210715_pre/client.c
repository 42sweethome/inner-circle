/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 17:00:46 by junghan          ###   ########.fr       */
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
		usleep(50);
	}
}

void	check(int signo)
{
	write(1, "GOT IT\n", 7);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	my;
	int	idx;
	char	*str;
	struct sigaction	new_tmp;

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
		write(1, "arg error\n", 10);\
	return (0);
}
