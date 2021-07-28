/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by doyun             #+#    #+#             */
/*   Updated: 2021/07/26 11:49:06 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	move(t_info *info, int x, int y)
{
	if (info->map.map[info->map.player_y + y][info->map.player_x + x] != '1')
	{
		if (info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'E')
			ft_exit(info);
		if (info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'C')
			info->map.collect -= 1;
		if (!(info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'E' && info->map.collect != 0))
		{
			info->map.map[info->map.player_y][info->map.player_x] = '0';
			info->map.map[info->map.player_y += y] \
			[info->map.player_x += x] = 'P';
			printf("how many walk : %d\n", ++info->map.walk);
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
		exit(0);
	return (0);
}

int	check_button(void)
{
	exit(0);
	return (0);
}
