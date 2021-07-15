/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:23:13 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 12:12:41 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli.h"

/*
void sig_usr2(int signo)
{
    printf("0\n");
}
*/

void sig_usr1(int signo)
{
	static char	arr[8];
	static int	i;
	char		set;

/*	if (i == 0)
	{	
		set = -1;
		while (++set < 8)
			arr[set] = 0;
	}*/
	if (signo == 30)
   	 	arr[i] = '1';
	else if (signo == 31)
		arr[i] = '0';
	i++;
	if (i == 8)
	{
		set = (char)ft_atoi_base(arr, "01");
		printf("%c\n", set);
		i = 0;
	}
}

int	main()
{
	struct sigaction new_tmp1;
	//struct sigaction old_tmp1;
	//struct sigaction new_tmp2;
	//struct sigaction old_tmp2;
	int i;

	new_tmp1.sa_handler = sig_usr1;
	//old_tmp1.sa_handler = sig_usr1;
	//new_tmp2.sa_handler = sig_usr2;
	//old_tmp2.sa_handler = sig_usr2;

	sigaction(SIGUSR1, &new_tmp1, 0);//&old_tmp1);
	sigaction(SIGUSR2, &new_tmp1, 0);//&old_tmp2);

	i = 0;
	while (1)
	{
//		printf("%d\n", i++);
		sleep(1);
	}
	return (0);
}
