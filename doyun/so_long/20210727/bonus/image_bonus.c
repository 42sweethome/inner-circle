/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:26:29 by doyun             #+#    #+#             */
/*   Updated: 2021/07/27 15:29:05 by doyun            ###   ########.fr       */
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
			tex.img_width * 2 + width];
		}
	}
	return (0);
}

void	get_texture2(t_info *info)
{
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
	info->tex[5].addr = (int *)mlx_get_data_addr(info->tex[5].img, &info->\
	tex[5].bits_per_pixel, &info->tex[5].line_length, &info->tex[5].endian);
	info->tex[6].addr = (int *)mlx_get_data_addr(info->tex[6].img, &info->\
	tex[6].bits_per_pixel, &info->tex[6].line_length, &info->tex[6].endian);
	info->tex[7].addr = (int *)mlx_get_data_addr(info->tex[7].img, &info->\
	tex[7].bits_per_pixel, &info->tex[7].line_length, &info->tex[7].endian);
	info->tex[8].addr = (int *)mlx_get_data_addr(info->tex[8].img, &info->\
	tex[8].bits_per_pixel, &info->tex[8].line_length, &info->tex[8].endian);
	info->tex[9].addr = (int *)mlx_get_data_addr(info->tex[9].img, &info->\
	tex[9].bits_per_pixel, &info->tex[9].line_length, &info->tex[9].endian);
	info->tex[10].addr = (int *)mlx_get_data_addr(info->tex[10].img, &info->\
	tex[10].bits_per_pixel, &info->tex[10].line_length, &info->tex[10].endian);
	info->tex[11].addr = (int *)mlx_get_data_addr(info->tex[11].img, &info->\
	tex[11].bits_per_pixel, &info->tex[11].line_length, &info->tex[11].endian);
	info->tex[12].addr = (int *)mlx_get_data_addr(info->tex[12].img, &info->\
	tex[12].bits_per_pixel, &info->tex[12].line_length, &info->tex[12].endian);
	info->tex[13].addr = (int *)mlx_get_data_addr(info->tex[13].img, &info->\
	tex[13].bits_per_pixel, &info->tex[13].line_length, &info->tex[13].endian);

}

void	get_texture(t_info *info)
{
	info->tex[0].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/dfloor.xpm", &info->tex[0].img_width, &info->tex[0].img_height);
	info->tex[1].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/wall.xpm", &info->tex[1].img_width, &info->tex[1].img_height);
	info->tex[2].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/collect.xpm", &info->tex[2].img_width, &info->tex[2].img_height);
	info->tex[3].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/dend.xpm", &info->tex[3].img_width, &info->tex[3].img_height);
	info->tex[4].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/left1.xpm", &info->tex[4].img_width, &info->tex[4].img_height);
	info->tex[5].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/left2.xpm", &info->tex[5].img_width, &info->tex[5].img_height);
	info->tex[6].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/right1.xpm", &info->tex[6].img_width, &info->tex[6].img_height);
	info->tex[7].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/right2.xpm", &info->tex[7].img_width, &info->tex[7].img_height);
	info->tex[8].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/back1.xpm", &info->tex[8].img_width, &info->tex[8].img_height);
	info->tex[9].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/back2.xpm", &info->tex[9].img_width, &info->tex[9].img_height);
	info->tex[10].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/front_left.xpm", &info->tex[10].img_width, &info->tex[10].img_height);
	info->tex[11].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/front_right.xpm", &info->tex[11].img_width, &info->tex[11].img_height);
	info->tex[12].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/ghost.xpm", &info->tex[12].img_width, &info->tex[12].img_height);
	info->tex[13].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/ghost_right.xpm", &info->tex[13].img_width, &info->tex[13].img_height);
	get_texture2(info);
}

int	img_conv(t_info *info)
{
	int		y;
	int		x;

	y = -1;
	get_texture(info);
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
				draw(info, y, x, info->tex[info->map.way]);
			else if (info->map.map[y][x] == 'V')
				draw(info, y, x, info->tex[7]);
			printf("where : %d %d %c\n", x, y, info->map.map[y][x]);
		}
	}

	mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, \
	info->fimg.img, 0, 0);
	mlx_string_put(info->win.mlx, info->win.mlx_win, 0, 12, 0xFFFFFF, ft_itoa(info->map.walk));
	if (info->map.v == 1)
		villain(info);
	return (0);
}
