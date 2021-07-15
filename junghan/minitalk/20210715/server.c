/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 13:52:59 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli.h"

void sig_usr(int signo)
{
	static char	arr[8];
	static int	i;
	char		set;

	if (signo == 30)
   	 	arr[i] = '1';
	else if (signo == 31)
		arr[i] = '0';
	i++;
	if (i == 8)
	{
		set = (char)ft_atoi_base(arr, "01");
		write(1, &set, 1);
		i = 0;
	}
}

int	main()
{
	struct sigaction new_tmp;
	int i;

	new_tmp.sa_handler = sig_usr;

	sigaction(SIGUSR1, &new_tmp, 0);
	sigaction(SIGUSR2, &new_tmp, 0);

	i = 0;
	while (1)
	{
//		printf("%d\n", i++);
		sleep(1);
	}
	return (0);
}
