/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by doyun             #+#    #+#             */
/*   Updated: 2021/07/27 14:40:39 by doyun            ###   ########.fr       */
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
			info->map.collect -= 1;
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
	if (key == 126)
	{
		move(info, 0, -1);
		info->map.way = 8 + (info->map.walk % 2);
	}
	else if (key == 125)
	{
		move(info, 0, 1);
		info->map.way = 10 + (info->map.walk % 2);
	}
	else if (key == 123)
	{
		move(info, -1, 0);
		info->map.way = 6 + (info->map.walk % 2);
	}
	else if (key == 124)
	{
		move(info, 1, 0);
		info->map.way = 4 + (info->map.walk % 2);
	}
	else if (key == 53)
		exit(0);
	return (0);
}

int	check_button(void)
{
	exit(0);
	return (0);
}

void	patrol(t_info *info, int i, int l)
{
	info->map.map[info->map.v_y][info->map.v_x] = '0';
	info->map.map[info->map.v_y][info->map.v_x += i] = 'V';
	info->map.v_d = 0;
	if (l == 1)
		die();
}

void	villain(t_info *info)
{
	static int	i;
	static int	check;

	if (i++ >= 100)
	{
		if (check == 0)
		{
			if (info->map.map[info->map.v_y][info->map.v_x + 1] == '0')
				patrol(info ,1 ,0);
			else if (info->map.map[info->map.v_y][info->map.v_x + 1] == 'P')
				patrol(info, 1, 1);
			else
				check = 1;
		}
		if (check == 1)
		{
			if (info->map.map[info->map.v_y][info->map.v_x - 1] == '0')
				patrol(info, -1, 0);
			else if (info->map.map[info->map.v_y][info->map.v_x - 1] == 'P')
				patrol(info, -1, 1);
			else
				check = 0;
		}
		i = 0;
		info->map.v_d = check;
	}
}
