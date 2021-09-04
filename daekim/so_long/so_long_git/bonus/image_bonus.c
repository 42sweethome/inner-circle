/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:46:58 by daekim            #+#    #+#             */
/*   Updated: 2021/09/04 11:46:59 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw(t_info *info, int x, int y, t_data tex)
{
	int		width;
	int		height;

	height = -1;
	while (++height < tex.img_height)
	{
		width = -1;
		while (++width < tex.img_width)
		{
			info->fimg.addr[tex.img_width * (y + info->map.col * (height + \
						tex.img_height * x)) + width] = tex.addr[height * \
				tex.img_width + width];
		}
	}
	return (0);
}

void	draw_conf(t_info *info, int x, int y)
{
	if (x == info->map.v_x && y == info->map.v_y \
		&& info->map.map[x][y] != 'P' && info->map.v_f >= 0)
	{
		info->map.map[x][y] = 'V';
		info->map.v_f = -2;
	}
	if (info->map.map[x][y] == '0')
		draw(info, x, y, info->tex[0]);
	else if (info->map.map[x][y] == '1')
		draw(info, x, y, info->tex[1]);
	else if (info->map.map[x][y] == 'C')
		draw(info, x, y, info->tex[info->map.c]);
	else if (info->map.map[x][y] == 'E')
		draw(info, x, y, info->tex[6]);
	else if (info->map.map[x][y] == 'P')
		draw(info, x, y, info->tex[info->map.way]);
	else if (info->map.map[x][y] == 'V')
		draw(info, x, y, info->tex[15 + info->map.v_d]);
}

int	img_conv(t_info *info)
{
	int		x;
	int		y;
	char	*c;

	x = -1;
	while (++x < info->map.row)
	{
		y = -1;
		while (++y < info->map.col)
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
