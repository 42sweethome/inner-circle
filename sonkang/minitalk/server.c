/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by sonkang           #+#    #+#             */
/*   Updated: 2021/07/19 21:19:06 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli.h"

void	output(char *arr, int *i)
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
	}
	*i = 0;
}

void	sig_usr(int signo)
{
	static char	arr[8];
	static int	i;

	if (signo == 30)
		arr[i] = '1';
	else if (signo == 31)
		arr[i] = '0';
	i++;
	if (i == 8)
		output(arr, &i);
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
