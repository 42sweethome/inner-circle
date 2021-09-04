/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:43:17 by daekim            #+#    #+#             */
/*   Updated: 2021/09/04 11:43:18 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli_bonus.h"

void	change_base(int pid, int ch)
{
	int				idx;
	unsigned char	filter;

	filter = 0x80;
	idx = -1;
	while (++idx < 8)
	{
		if (ch & filter)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		filter = filter >> 1;
		usleep(100);
	}
}

void	check(int signo)
{
	if (signo == SIGUSR1)
		write(1, "GOT IT\n", 7);
}

void	send_sig(int pid, unsigned char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		change_base(pid, str[idx]);
	change_base(pid, 0);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					my;
	unsigned char		*str;
	struct sigaction	new_tmp;

	new_tmp.sa_handler = check;
	sigaction(SIGUSR1, &new_tmp, 0);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = (unsigned char *)ft_strdup(argv[2]);
		send_sig(pid, str);
		free(str);
		str = 0;
		my = getpid();
		str = (unsigned char *)ft_itoa(my);
		send_sig(pid, str);
		free(str);
		str = 0;
	}
	else
		write(1, "arg error\n", 10);
	return (0);
}
