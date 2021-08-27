/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by sonkang           #+#    #+#             */
/*   Updated: 2021/07/19 21:17:21 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli.h"

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
	unsigned char		*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = (unsigned char *)ft_strdup(argv[2]);
		send_sig(pid, str);
		free(str);
		str = 0;
	}
	else
		write(1, "arg error\n", 10);
	return (0);
}
