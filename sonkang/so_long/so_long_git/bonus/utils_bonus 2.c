/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by sonkang           #+#    #+#             */
/*   Updated: 2021/08/17 23:50:27 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(t_info *info)
{
	int		x;

	mlx_destroy_window(info->win.mlx, info->win.mlx_win);
	mlx_destroy_image(info->win.mlx, info->fimg.img);
	x = -1;
	while (++x < 17)
		mlx_destroy_image(info->win.mlx, info->tex[x].img);
	exit(0);
}

void	message(t_info *info)
{
	if (info->map.collect == 0)
	{
		printf("SUCCESS!\n");
		ft_exit(info);
	}
	else
		printf("EAT THE CAKE!\n");
}

void	die(t_info *info)
{
	printf("FAIL!\n");
	ft_exit(info);
}

int	check_button(t_info *info)
{
	ft_exit(info);
	return (0);
}
