/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by doyun             #+#    #+#             */
/*   Updated: 2021/07/30 10:58:52 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(t_info *info)
{
	if (info->map.collect == 0)
	{
		printf("well done\n");
		exit(0);
	}
	else
		printf("keep going!\n");
}

void	die(void)
{
	printf("you die...\n");
	exit(0);
}

int	check_button(void)
{
	exit(0);
	return (0);
}
