/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_conversion2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:17:36 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/24 10:19:18 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_floor_ceilling(t_info *info, int x)
{
	int		y;

	y = -1;
	while (++y < info->dda.draw_start)
		info->fimg.addr[info->win.win_w * y + x] = info->map.ceilling;
	y = info->dda.draw_end - 1;
	while (++y < info->win.win_h)
		info->fimg.addr[info->win.win_w * y + x] = info->map.floor;
}

void	draw_column(t_info *info, int x, int y)
{
	info->grap.img_y = (int)(info->grap.img_height * \
		info->grap.obj_y / info->dda.line_height);
	if (info->dda.side == 1)
	{
		if (info->dda.raydir_y < 0)
			info->grap.text_num = 0;
		else
			info->grap.text_num = 1;
	}
	else
	{
		if (info->dda.raydir_x < 0)
			info->grap.text_num = 2;
		else
			info->grap.text_num = 3;
	}
	info->fimg.addr[info->win.win_w * y + x] = \
		info->tex[info->grap.text_num].addr[info->tex \
		[info->grap.text_num].img_width * info->grap.img_y + info->grap.img_x];
	info->grap.obj_y++;
}

void	affine_texture_mapping(t_info *info, int x)
{
	int		y;

	paint_floor_ceilling(info, x);
	if (info->dda.side == 0)
		info->grap.obj_x = info->user.pos_y + info->dda.perp \
			* info->dda.raydir_y;
	else
		info->grap.obj_x = info->user.pos_x + info->dda.perp * \
			info->dda.raydir_x;
	info->grap.img_x = (int)(info->tex[0].img_width * \
			(info->grap.obj_x - floor(info->grap.obj_x)));
	info->grap.obj_y = 0;
	if (info->dda.draw_start == 0)
		info->grap.obj_y = info->dda.line_height / 2 - info->win.win_h / 2;
	y = info->dda.draw_start - 1;
	while (++y < info->dda.draw_end)
		draw_column(info, x, y);
}

void	draw(t_info *info)
{
	mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, \
		info->fimg.img, 0, 0);
}
