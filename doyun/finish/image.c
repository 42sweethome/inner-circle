/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by doyun             #+#    #+#             */
/*   Updated: 2021/07/30 11:11:20 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	get_texture(t_info *info)
{
	info->tex[0].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/dfloor.xpm", &info->tex[0].img_width, &info->tex[0].img_height);
	info->tex[1].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/dwall.xpm", &info->tex[1].img_width, &info->tex[1].img_height);
	info->tex[2].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/dcollect1.xpm", &info->tex[2].img_width, &info->tex[2].img_height);
	info->tex[3].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/dexit.xpm", &info->tex[3].img_width, &info->tex[3].img_height);
	info->tex[4].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/dfront1.xpm", &info->tex[4].img_width, &info->tex[4].img_height);
	info->tex[0].addr = (int *)mlx_get_data_addr(info->tex[0].img, &info->\
	tex[0].bits_per_pixel, &info->tex[0].line_length, &info->tex[0].endian);
	info->tex[1].addr = (int *)mlx_get_data_addr(info->tex[1].img, &info->\
	tex[1].bits_per_pixel, &info->tex[1].line_length, &info->tex[1].endian);
	info->tex[2].addr = (int *)mlx_get_data_addr(info->tex[2].img, &info->\
	tex[2].bits_per_pixel, &info->tex[2].line_length, &info->tex[2].endian);
	info->tex[3].addr = (int *)mlx_get_data_addr(info->tex[3].img, &info->\
	tex[3].bits_per_pixel, &info->tex[3].line_length, &info->tex[3].endian);
	info->tex[4].addr = (int *)mlx_get_data_addr(info->tex[4].img, &info->\
	tex[4].bits_per_pixel, &info->tex[4].line_length, &info->tex[4].endian);
}

int	img_conv(t_info *info)
{
	int		y;
	int		x;

	y = -1;
	while (++y < info->map.row)
	{
		x = -1;
		while (++x < info->map.col)
		{
			if (info->map.map[y][x] == '0')
				draw(info, y, x, info->tex[0]);
			else if (info->map.map[y][x] == '1')
				draw(info, y, x, info->tex[1]);
			else if (info->map.map[y][x] == 'C')
				draw(info, y, x, info->tex[2]);
			else if (info->map.map[y][x] == 'E')
				draw(info, y, x, info->tex[3]);
			else if (info->map.map[y][x] == 'P')
				draw(info, y, x, info->tex[4]);
		}
	}
	mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, \
	info->fimg.img, 0, 0);
	return (0);
}
