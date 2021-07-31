/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:26:29 by sonkang           #+#    #+#             */
/*   Updated: 2021/07/31 14:50:07 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw(t_info *info, int y, int x, t_data tex)
{
	int		width;
	int		height;

	height = -1;
	while (++height < tex.img_height)
	{
		width = -1;
		while (++width < tex.img_width)
		{
			info->fimg.addr[tex.img_width * (x + info->map.col * (height + \
						tex.img_height * y)) + width] = tex.addr[height * \
				tex.img_width + width];
		}
	}
	return (0);
}

void	draw_conf(t_info *info, int x, int y)
{
	if (x == info->map.v_x && y == info->map.v_y \
		&& info->map.map[y][x] != 'P' && info->map.v_f >= 0)
	{
		info->map.map[y][x] = 'V';
		info->map.v_f = -2;
	}
	if (info->map.map[y][x] == '0')
		draw(info, y, x, info->tex[0]);
	else if (info->map.map[y][x] == '1')
		draw(info, y, x, info->tex[1]);
	else if (info->map.map[y][x] == 'C')
		draw(info, y, x, info->tex[info->map.c]);
	else if (info->map.map[y][x] == 'E')
		draw(info, y, x, info->tex[6]);
	else if (info->map.map[y][x] == 'P')
		draw(info, y, x, info->tex[info->map.way]);
	else if (info->map.map[y][x] == 'V')
		draw(info, y, x, info->tex[15 + info->map.v_d]);
}

int	img_conv(t_info *info)
{
	int		y;
	int		x;
	char	*c;

	y = -1;
	while (++y < info->map.row)
	{
		x = -1;
		while (++x < info->map.col)
			draw_conf(info, x, y);
	}
	mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, \
			info->fimg.img, 0, 0);
	c = ft_itoa(info->map.walk);
	mlx_string_put(info->win.mlx, info->win.mlx_win, 0, 12, 0xFFFFFF, c);
	free(c);
	collectible(info);
	if (info->map.v_f == -2)
		villain(info);
	return (0);
}
