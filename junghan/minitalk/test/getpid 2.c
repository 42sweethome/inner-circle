/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:27:15 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 10:18:39 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	main()
{
	int pid;
	
	pid = getpid();
	printf("%d\n",pid);
	return (0);
}
