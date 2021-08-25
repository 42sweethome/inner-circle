/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 15:03:49 by junghan          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid;
	int	idx;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = ft_strdup(argv[2]);

		idx = -1;//보완필요
		while (str[++idx])//문자
			change_base(pid, str[idx]);
		change_base(pid, 0);
	}
	else
		write(1, "arg error\n", 10);
	return (0);
}
