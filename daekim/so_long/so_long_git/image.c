/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:45:15 by daekim            #+#    #+#             */
/*   Updated: 2021/09/04 11:45:16 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	get_texture(t_info *info)
{
	info->tex[0].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/elinia2.xpm", &info->tex[0].img_width, &info->tex[0].img_height);
	info->tex[1].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/elinia_sky1.xpm", &info->tex[1].img_width, &info->tex[1].img_height);
	info->tex[2].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/elinia.xpm", &info->tex[2].img_width, &info->tex[2].img_height);
	info->tex[3].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/exit.xpm", &info->tex[3].img_width, &info->tex[3].img_height);
	info->tex[4].img = mlx_xpm_file_to_image(info->win.mlx, \
	"./texture/fro_l.xpm", &info->tex[4].img_width, &info->tex[4].img_height);
	info->tex[0].addr = (unsigned int *)mlx_get_data_addr(info->tex[0].img, \
	&info->tex[0].bits_per_pixel, &info->tex[0].line_length, \
	&info->tex[0].endian);
	info->tex[1].addr = (unsigned int *)mlx_get_data_addr(info->tex[1].img, \
	&info->tex[1].bits_per_pixel, &info->tex[1].line_length, \
	&info->tex[1].endian);
	info->tex[2].addr = (unsigned int *)mlx_get_data_addr(info->tex[2].img, \
	&info->tex[2].bits_per_pixel, &info->tex[2].line_length, \
	&info->tex[2].endian);
	info->tex[3].addr = (unsigned int *)mlx_get_data_addr(info->tex[3].img, \
	&info->tex[3].bits_per_pixel, &info->tex[3].line_length, \
	&info->tex[3].endian);
	info->tex[4].addr = (unsigned int *)mlx_get_data_addr(info->tex[4].img, \
	&info->tex[4].bits_per_pixel, &info->tex[4].line_length, \
	&info->tex[4].endian);
}

int	img_conv(t_info *info)
{
	int		x;
	int		y;

	x = -1;
	while (++x < info->map.row)
	{
		y = -1;
		while (++y < info->map.col)
		{
			if (info->map.map[x][y] == '0')
				draw(info, x, y, info->tex[0]);
			else if (info->map.map[x][y] == '1')
				draw(info, x, y, info->tex[1]);
			else if (info->map.map[x][y] == 'C')
				draw(info, x, y, info->tex[2]);
			else if (info->map.map[x][y] == 'E')
				draw(info, x, y, info->tex[3]);
			else if (info->map.map[x][y] == 'P')
				draw(info, x, y, info->tex[4]);
		}
	}
	mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, \
	info->fimg.img, 0, 0);
	return (0);
}
