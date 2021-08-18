/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by sonkang           #+#    #+#             */
/*   Updated: 2021/08/11 22:53:38 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_info *info)
{
	int		x;

	mlx_destroy_window(info->win.mlx, info->win.mlx_win);
	mlx_destroy_image(info->win.mlx, info->fimg.img);
	x = -1;
	while (++x < 5)
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

void	move(t_info *info, int x, int y)
{
	if (info->map.map[info->map.player_y + y][info->map.player_x + x] != '1')
	{
		if (info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'E')
			message(info);
		if (info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'C')
			info->map.collect -= 1;
		if (!(info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'E' && info->map.collect != 0))
		{
			info->map.map[info->map.player_y][info->map.player_x] = '0';
			info->map.map[info->map.player_y += y] \
			[info->map.player_x += x] = 'P';
			printf("WALK : %d\n", ++info->map.walk);
		}
	}
}

int	check_keypress(int key, t_info *info)
{
	if (key == 13)
		move(info, 0, -1);
	else if (key == 1)
		move(info, 0, 1);
	else if (key == 0)
		move(info, -1, 0);
	else if (key == 2)
		move(info, 1, 0);
	else if (key == 53)
		ft_exit(info);
	return (0);
}

int	check_button(t_info *info)
{
	ft_exit(info);
	return (0);
}
