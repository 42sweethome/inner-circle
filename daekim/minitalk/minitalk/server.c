/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by junghan           #+#    #+#             */
/*   Updated: 2021/07/16 10:47:43 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli.h"

void	reply(int *end, int signo)
{
	static char	arr[8];
	static int	i;
	static int	cli_pid;
	static char	*pid;
	char		set;

//	printf("-1- %d %d \n", i, signo);
	if (signo == 30)
		arr[i] = '1';
	else if (signo == 31)
		arr[i] = '0';
//	printf("-2-\n");
	i++;
	if (i == 8 && *end == 1)
	{
		set = (char)ft_atoi_base(arr, "01");
		if (set == 0)
			*end = 0;
		if (pid == 0)
			pid = ft_strdup("");
		pid = ft_strjoin((char const *)pid, (char const *)&set);
		i = 0;
	}
//	printf("-3-\n");
	if (*end == 0 && set == 0)
	{
		cli_pid = ft_atoi(pid);
		kill(cli_pid, SIGUSR1);
		free(pid);
		pid = 0;
		cli_pid = 0;
	}
//	printf("-4-\n");
}

void sig_usr(int signo)
{
	static char	arr[8];
	static int	i;
	static int	end;
	char		set;

	if (end == 0)
	{
		if (signo == 30)
			arr[i] = '1';
		else if (signo == 31)
			arr[i] = '0';
		i++;
		if (i == 8)
		{
			set = (char)ft_atoi_base(arr, "01");
			write(1, &set, 1);
			if (set == 0)
			{
				write(1, "\n", 1);
				i = -1;
				while (++i < 8)
					arr[i] = 0;
				end = 1;
			}
			i = 0;
		}
	}
	else
		reply(&end, signo);
}

int	main()
{
	struct sigaction new_tmp;
	int num;
	char *pid;

	new_tmp.sa_handler = sig_usr;

	num = getpid();
	pid = ft_itoa(num);
	num = ft_strlen(pid);
	write(1, "PID: [", 6);
	write(1, pid, num);
	write(1, "] : \n", 5);

	while (42)
	{
		sigaction(SIGUSR1, &new_tmp, 0);
		sigaction(SIGUSR2, &new_tmp, 0);
	}
	return (0);
}
