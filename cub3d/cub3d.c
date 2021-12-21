#include "cub3d.h"

void	paint_f_c(t_info *info, int x)
{
	int y;

	y = -1;
	while (++y < info->dda.draw_start)
		info->fimg.addr[info->win.win_w * y + x] = info->map.ceilling;
	y = info->dda.draw_end - 1;
	while (++y < info->win.win_h)
		info->fimg.addr[info->win.win_w * y + x] = info->map.floor;
}

void	affine_texture_mapping(t_info *info, int x)
{
	int		y;

	paint_f_c(info, x);
	if (info->dda.side == 0)
		info->graphic.obj_x = info->user.pos_y + info->dda.perpwalldist * info->dda.raydir_y;
	else
		info->graphic.obj_x = info->user.pos_x + info->dda.perpwalldist * info->dda.raydir_x;
	info->graphic.img_x = (int)(info->tex[0].img_width * (info->graphic.obj_x - floor(info->graphic.obj_x)));
	info->graphic.obj_y = 0;
	if (info->dda.draw_start == 0)
		info->graphic.obj_y = info->dda.line_height / 2 - info->win.win_h / 2;
	y =info->dda.draw_start - 1;
	while (++y < info->dda.draw_end)
	{
		info->graphic.img_y = (int)(info->graphic.img_height * info->graphic.obj_y / info->dda.line_height);
		info->graphic.tex_point = info->graphic.size_l / (info->graphic.bpp / 8) * info->graphic.img_y + info->graphic.img_x;
		if (info->dda.side == 0)
		{
			if (info->dda.raydir_x > 0)
				info->graphic.text_num = 0;
			else
				info->graphic.text_num = 1;
		}
		else
		{
			if (info->dda.raydir_y > 0)
				info->graphic.text_num = 2;
			else
				info->graphic.text_num = 3;
		}
		info->fimg.addr[info->win.win_w * y + x] = \
		info->tex[info->graphic.text_num].addr[info->tex[info->graphic.text_num].img_width * \
			info->graphic.img_y + info->graphic.img_x];
		info->graphic.obj_y++;
	}
}

void	win_init(t_win *win)
{
	win->win_w = 1024;
	win->win_h = 768;
}

void	user_init(t_info *info)
{
	info->user.move_speed = 0.1;
	info->user.rot_speed = 0.1;
	info->user.pos_x = info->map.player_x + 0.5;
	info->user.pos_y = info->map.player_y + 0.5;
	if (info->map.direction == 'N' || info->map.direction == 'S')
	{
		if (info->map.direction == 'N')
		{
			info->user.dir_y = -1;
			info->user.plane_y = 0.0;
			info->user.plane_x = 0.66;
		}
		else
		{
			info->user.dir_y = 1;
			info->user.plane_y = 0.0;
			info->user.plane_x = -0.66;
		}
		info->user.dir_x = 0;
	}
	else
	{
		if (info->map.direction == 'E')
		{
			info->user.dir_x = 1;
			info->user.plane_y = 0.66;
			info->user.plane_x = 0.0;
		}
		else
		{
			info->user.dir_x = -1;
			info->user.plane_y = -0.66;
			info->user.plane_x = 0.0;
		}
	
		info->user.dir_y = 0;
	}	
	info->map.map[info->map.player_y][info->map.player_x] = '0';
}

void	graphic_init(t_info *info)
{
	user_init(info);
	win_init(&(info->win));
	info->graphic.img_width = 64;
	info->graphic.img_height = 64;
	info->graphic.size_l = 256;
	info->graphic.bpp = 32;
}

void	paint_floor_ceiling(t_info *info)
{
	int		x;
	int		y;

	y = -1;
	while (++y < info->win.win_h)
	{
		x = -1;
		while (++x < info->win.win_w)
		{
			if (y < info->win.win_h / 2)
				info->fimg.addr[info->win.win_w * y + x] = info->map.ceilling;
			else
				info->fimg.addr[info->win.win_w * y + x] = info->map.floor;
		}
	}
}

void	draw(t_info *info)
{
	mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, \
	info->fimg.img, 0, 0);
}

int	img_conv(t_info *info)
{
	int		x;

	//paint_floor_ceiling(info);
	x = -1;
	while (++x < info->win.win_w)
	{
		info->dda.camera_x = 2 * x / (double)info->win.win_w - 1;
		info->dda.raydir_x = info->user.dir_x + info->user.plane_x * info->dda.camera_x;
		info->dda.raydir_y = info->user.dir_y + info->user.plane_y * info->dda.camera_x;
		info->dda.map_x = (int)info->user.pos_x;
		info->dda.map_y = (int)info->user.pos_y;
		info->dda.deltadist_x = fabs(1 / info->dda.raydir_x);
		info->dda.deltadist_y = fabs(1 / info->dda.raydir_y);
		info->dda.hit = 0;
		if (info->dda.raydir_x < 0)
		{
			info->dda.step_x = -1;
			info->dda.sidedist_x = (info->user.pos_x - info->dda.map_x) * info->dda.deltadist_x;
		}
		else
		{
			info->dda.step_x = 1;
			info->dda.sidedist_x = (info->dda.map_x + 1 - info->user.pos_x) * info->dda.deltadist_x;
		}
		if (info->dda.raydir_y < 0)
		{
			info->dda.step_y = -1;
			info->dda.sidedist_y = (info->user.pos_y - info->dda.map_y) * info->dda.deltadist_y;
		}
		else
		{
			info->dda.step_y = 1;
			info->dda.sidedist_y = (info->dda.map_y + 1 - info->user.pos_y) * info->dda.deltadist_y;
		}
		while (info->dda.hit == 0)
		{
			if (info->dda.sidedist_x < info->dda.sidedist_y)
			{
				info->dda.sidedist_x += info->dda.deltadist_x;
				info->dda.map_x += info->dda.step_x;
				info->dda.side = 0;
			}
			else
			{
				info->dda.sidedist_y += info->dda.deltadist_y;
				info->dda.map_y += info->dda.step_y;
				info->dda.side = 1;
			}
			if (info->map.map[info->dda.map_y][info->dda.map_x] == '1' || \
				info->map.map[info->dda.map_y][info->dda.map_x] == ' ')
				info->dda.hit = 1;
		}
		if (info->dda.side == 0)
			info->dda.perpwalldist = (info->dda.map_x - info->user.pos_x + (1 - info->dda.step_x) / 2) / info->dda.raydir_x;
		else
			info->dda.perpwalldist = (info->dda.map_y - info->user.pos_y + (1 - info->dda.step_y) / 2) / info->dda.raydir_y;
		info->dda.line_height = (int)(info->win.win_h / info->dda.perpwalldist);
		info->dda.draw_start = info->win.win_h / 2 - info->dda.line_height / 2;
		if (info->dda.draw_start < 0)
			info->dda.draw_start = 0;
		info->dda.draw_end = info->win.win_h / 2 + info->dda.line_height / 2;
		if (info->dda.draw_end >= info->win.win_h)
			info->dda.draw_end = info->win.win_h - 1;
		affine_texture_mapping(info, x);
	}
	printf("pos x : %f pos y :  %f\n", info->user.pos_x, info->user.pos_y);
	draw(info);
	return (0);
}



int	check_button(t_info *info)
{
 	ft_exit(info);
 	return (0);
}

int	check_keypress(int key, t_info *info)
{
	double		old;

	if (key == 13)
	{
		if (info->map.map[(int)(info->user.pos_y + info->user.dir_y * info->user.move_speed)]\
			[(int)info->user.pos_x] == '0')
			info->user.pos_y += info->user.dir_y * info->user.move_speed;
		if (info->map.map[(int)info->user.pos_y]\
			[(int)(info->user.pos_x + info->user.dir_x * info->user.move_speed)] == '0')
			info->user.pos_x += info->user.dir_x * info->user.move_speed;
	}
	else if (key == 1)
	{
		if (info->map.map[(int)(info->user.pos_y - info->user.dir_y * info->user.move_speed)]\
			[(int)info->user.pos_x] == '0')
			info->user.pos_y -= info->user.dir_y * info->user.move_speed;
		if (info->map.map[(int)info->user.pos_y]\
			[(int)(info->user.pos_x - info->user.dir_x * info->user.move_speed)] == '0')
			info->user.pos_x -= info->user.dir_x * info->user.move_speed;
	}
	else if (key == 0)
	{
		if (info->map.map[(int)(info->user.pos_y - info->user.plane_y * info->user.move_speed)]\
			[(int)info->user.pos_x] == '0')
			info->user.pos_y -= info->user.plane_y * info->user.move_speed;
		if (info->map.map[(int)info->user.pos_y]\
			[(int)(info->user.pos_x - info->user.plane_x * info->user.move_speed)] == '0')
			info->user.pos_x -= info->user.plane_x * info->user.move_speed;
	}
	else if (key == 2)
	{
		if (info->map.map[(int)(info->user.pos_y + info->user.plane_y * info->user.move_speed)]\
			[(int)info->user.pos_x] == '0')
			info->user.pos_y += info->user.plane_y * info->user.move_speed;
		if (info->map.map[(int)info->user.pos_y]\
			[(int)(info->user.pos_x + info->user.plane_x * info->user.move_speed)] == '0')
			info->user.pos_x += info->user.plane_x * info->user.move_speed;
	}
	else if (key == 123)
	{
		old = info->user.dir_x;
		info->user.dir_x = info->user.dir_x * cos(-info->user.rot_speed) - info->user.dir_y * sin(-info->user.rot_speed);
		info->user.dir_y = old * sin(-info->user.rot_speed) + info->user.dir_y * cos(-info->user.rot_speed);
		old = info->user.plane_x;
		info->user.plane_x = info->user.plane_x * cos(-info->user.rot_speed) - info->user.plane_y * sin(-info->user.rot_speed);
		info->user.plane_y = old * sin(-info->user.rot_speed) + info->user.plane_y * cos(-info->user.rot_speed);
	}
	else if (key == 124)
	{
		old = info->user.dir_x;
		info->user.dir_x = info->user.dir_x * cos(info->user.rot_speed) - info->user.dir_y * sin(info->user.rot_speed);
		info->user.dir_y = old * sin(info->user.rot_speed) + info->user.dir_y * cos(info->user.rot_speed);
		old = info->user.plane_x;
		info->user.plane_x = info->user.plane_x * cos(info->user.rot_speed) - info->user.plane_y * sin(info->user.rot_speed);
		info->user.plane_y = old * sin(info->user.rot_speed) + info->user.plane_y * cos(info->user.rot_speed);
	}
	else if (key == 53)
	 	ft_exit(info);
	return (0);
}

void	get_texture(t_info *info)
{
	info->tex[0].img = mlx_xpm_file_to_image(info->win.mlx, \
	info->map.path[0], &info->tex[0].img_width, &info->tex[0].img_height);
	info->tex[1].img = mlx_xpm_file_to_image(info->win.mlx, \
	info->map.path[1], &info->tex[1].img_width, &info->tex[1].img_height);
	info->tex[2].img = mlx_xpm_file_to_image(info->win.mlx, \
	info->map.path[2], &info->tex[2].img_width, &info->tex[2].img_height);
	info->tex[3].img = mlx_xpm_file_to_image(info->win.mlx, \
	info->map.path[3], &info->tex[3].img_width, &info->tex[3].img_height);
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
}

void	show_win(t_info *info)
{
	graphic_init(info);
	info->win.mlx = mlx_init();
	info->win.mlx_win = mlx_new_window(info->win.mlx, info->win.win_w, info->win.win_h, "cub3D");
	info->fimg.img = mlx_new_image(info->win.mlx, info->win.win_w, info->win.win_h);
	info->fimg.addr = (unsigned int *)mlx_get_data_addr(info->fimg.img, \
	&info->fimg.bits_per_pixel, &info->fimg.line_length, &info->fimg.endian);
	get_texture(info);
	mlx_hook(info->win.mlx_win, 2, 0, check_keypress, info);
	mlx_hook(info->win.mlx_win, 17, 0, check_button, info);
	mlx_loop_hook(info->win.mlx, img_conv, info);
	mlx_loop(info->win.mlx);
}

int parsing(char *argv, t_map *map)
{
	if (path_allocate(map))
		return (1);
	if (check_extention(argv, ".cub"))
		return (ft_error("Invaild extention(cub)"));
	if (get_element(argv, map))
		return (1);
	ft_printf(*map);
	return (0);
}

void	init_struct(t_info *info)
{
	int i;

	i = -1;
	while (++i < 6)
		info->map.wfc[i] = 0;
	info->map.cnt_wfc = 0;
	info->map.direction = 0;
	info->map.row = 0;
	info->map.cnt_nl = 0;
}

int main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		init_struct(&info);
		if (parsing(argv[1], &info.map))
		{
			return(1);
		}
		show_win(&info);
	}
	else
		return (ft_error("Invalid number of arguments"));
	return (0);
}
