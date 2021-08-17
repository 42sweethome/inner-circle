/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by sonkang           #+#    #+#             */
/*   Updated: 2021/08/17 22:58:42 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	message(t_info *info)
{
	if (info->map.collect == 0)
	{
		printf("well done\n");
		ft_exit(info);
	}
	else
		printf("keep going!\n");
}

void	die(t_info *info)
{
	printf("you die...\n");
	ft_exit(info);
}

int	check_button(t_info *info)
{
	ft_exit(info);
	return (0);
}
