/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 17:06:59 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli.h"

void	reply(int *end, int signo)
{
	static char	arr[8];
	static int	i;
	static char	*pid;
	char		set;

//	printf("-1- %d %d \n", i, signo);
	if (signo == 30)
		arr[i] = '1';
	else if (signo == 31)
		arr[i] = '0';
	sleep(1);
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
		i = ft_atoi(pid);
		kill(i, SIGUSR1);
		free(pid);
		pid = 0;
		i = 0;
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
	int i;
	int num;
	char *pid;

	new_tmp.sa_handler = sig_usr;

	sigaction(SIGUSR1, &new_tmp, 0);
	sigaction(SIGUSR2, &new_tmp, 0);

	num = getpid();
	pid = ft_itoa(num);
	num = ft_strlen(pid);
	write(1, "PID: [", 6);
	write(1, pid, num);
	write(1, "] : \n", 5);

	i = 0;
	while (1)
		pause();
	return (0);
}
