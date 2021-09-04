/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:45:29 by daekim            #+#    #+#             */
/*   Updated: 2021/09/04 11:45:30 by daekim           ###   ########.fr       */
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
	if (info->map.map[info->map.player_x + x][info->map.player_y + y] != '1')
	{
		if (info->map.map[info->map.player_x + x] \
			[info->map.player_y + y] == 'E')
			message(info);
		if (info->map.map[info->map.player_x + x] \
			[info->map.player_y + y] == 'C')
			info->map.collect -= 1;
		if (!(info->map.map[info->map.player_x + x] \
			[info->map.player_y + y] == 'E' && info->map.collect != 0))
		{
			info->map.map[info->map.player_x][info->map.player_y] = '0';
			info->map.map[info->map.player_x += x] \
			[info->map.player_y += y] = 'P';
			printf("WALK : %d\n", ++info->map.walk);
		}
	}
}

int	check_keypress(int key, t_info *info)
{
	if (key == 13)
		move(info, -1, 0);
	else if (key == 1)
		move(info, 1, 0);
	else if (key == 0)
		move(info, 0, -1);
	else if (key == 2)
		move(info, 0, 1);
	else if (key == 53)
		ft_exit(info);
	return (0);
}

int	check_button(t_info *info)
{
	ft_exit(info);
	return (0);
}
