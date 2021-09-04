/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:43:44 by daekim            #+#    #+#             */
/*   Updated: 2021/09/04 11:43:45 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli_bonus.h"

void	send_cli(char **pid)
{
	static int	cli_pid;

	cli_pid = ft_atoi(*pid);
	kill(cli_pid, SIGUSR1);
	free(*pid);
	*pid = 0;
	cli_pid = 0;
}

void	reply(int *end, int signo)
{
	static char	arr[8];
	static int	i;
	static char	*pid;
	char		set;

	if (signo == 30)
		arr[i] = '1';
	else if (signo == 31)
		arr[i] = '0';
	i++;
	if (i == 8 && *end == 1)
	{
		set = (char)ft_atoi_base(arr, "01");
		if (set == 0)
			*end = 0;
		if (pid == 0)
			pid = ft_strdup("");
		pid = ft_strjoin(pid, &set);
		i = 0;
	}
	if (*end == 0 && set == 0)
		send_cli(&pid);
}

void	output(char *arr, int *i, int *end)
{
	char	set;

	set = (char)ft_atoi_base(arr, "01");
	write(1, &set, 1);
	if (set == 0)
	{
		write(1, "\n", 1);
		*i = -1;
		while (++*i < 8)
			arr[*i] = 0;
		*end = 1;
	}
	*i = 0;
}

void	sig_usr(int signo)
{
	static char	arr[8];
	static int	i;
	static int	end;

	if (end == 0)
	{
		if (signo == 30)
			arr[i] = '1';
		else if (signo == 31)
			arr[i] = '0';
		i++;
		if (i == 8)
			output(arr, &i, &end);
	}
	else
		reply(&end, signo);
}

int	main(void)
{
	struct sigaction	new_tmp;
	int					num;
	char				*pid;

	new_tmp.sa_handler = sig_usr;
	num = getpid();
	pid = ft_itoa(num);
	num = ft_strlen(pid);
	write(1, "PID: [", 6);
	write(1, pid, num);
	write(1, "] : \n", 5);
	free(pid);
	pid = 0;
	while (42)
	{
		sigaction(SIGUSR1, &new_tmp, 0);
		sigaction(SIGUSR2, &new_tmp, 0);
	}
	return (0);
}
