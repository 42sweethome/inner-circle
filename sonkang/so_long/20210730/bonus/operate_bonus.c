/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by sonkang           #+#    #+#             */
/*   Updated: 2021/07/31 02:50:06 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move(t_info *info, int x, int y)
{
	if (info->map.map[info->map.player_y + y][info->map.player_x + x] != '1')
	{
		if (info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'V')
			die();
		if (info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'E')
			ft_exit(info);
		if (info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'C')
		{
			info->map.collect -= 1;
			if (info->map.collect == info->map.v_f - 1)
				get_villian_position(&info->map, info->map.player_y + y, \
				info->map.player_x + x);
		}
		if (!(info->map.map[info->map.player_y + y] \
			[info->map.player_x + x] == 'E' && info->map.collect != 0))
		{
			info->map.map[info->map.player_y][info->map.player_x] = '0';
			info->map.map[info->map.player_y += y] \
			[info->map.player_x += x] = 'P';
			info->map.walk++;
		}
	}
}

int	check_keypress(int key, t_info *info)
{
	if (key == 13)
	{
		move(info, 0, -1);
		info->map.way = 11 + (info->map.walk % 2);
	}
	else if (key == 1)
	{
		move(info, 0, 1);
		info->map.way = 13 + (info->map.walk % 2);
	}
	else if (key == 0)
	{
		move(info, -1, 0);
		info->map.way = 9 + (info->map.walk % 2);
	}
	else if (key == 2)
	{
		move(info, 1, 0);
		info->map.way = 7 + (info->map.walk % 2);
	}
	else if (key == 53)
		exit(0);
	return (0);
}

void	patrol(t_info *info, int i, int l)
{
	info->map.map[info->map.v_y][info->map.v_x] = '0';
	info->map.map[info->map.v_y][info->map.v_x + i] = 'V';
	info->map.v_x += i;
	info->map.v_d = 0;
	if (l == 1)
		die();
}

void	collectible(t_info *info)
{
	static int	i;

	if (i++ >= 10)
	{
		if (info->map.c < 5)
			info->map.c++;
		else
			info->map.c = 2;
		i = 0;
	}
}

void	villain(t_info *info)
{
	static int	i;

	if (i++ >= 100)
	{
		if (info->map.v_d == 0)
		{
			if (info->map.map[info->map.v_y][info->map.v_x + 1] == '0')
				patrol(info, 1, 0);
			else if (info->map.map[info->map.v_y][info->map.v_x + 1] == 'P')
				patrol(info, 1, 1);
			else
				info->map.v_d = 1;
		}
		if (info->map.v_d == 1)
		{
			if (info->map.map[info->map.v_y][info->map.v_x - 1] == '0')
				patrol(info, -1, 0);
			else if (info->map.map[info->map.v_y][info->map.v_x - 1] == 'P')
				patrol(info, -1, 1);
			else
				info->map.v_d = 0;
		}
		i = 0;
	}
}
