#include "cub3d.h"

void	ver_line(t_info *info, int x, int color)
{
	int		dot;

	dot = info->dda.draw_start - 1;
	while (++dot <= info->dda.draw_end)
		mlx_pixel_put(info->win.mlx, info->win.mlx_win, x, dot, color);
}

void	win_init(t_win *win)
{
	win->win_w = 256;
	win->win_h = 256;
}

void	user_init(t_info *info)
{
	info->user.pos_x = info->map.player_x;
	info->user.pos_y = info->map.player_y;
	info->user.plane_x = 0.0;
	info->user.plane_y = 0.66;
	if (info->map.direction == 'N' || info->map.direction == 'S')
	{
		if (info->map.direction == 'N')
			info->user.dir_x = 1;
		else
			info->user.dir_x = -1;
		info->user.dir_y = 0;
	}
	else
	{
		if (info->map.direction == 'E')
			info->user.dir_y = 1;
		else
			info->user.dir_y = -1;
		info->user.dir_x = 0;
	}
}

void	graphic_init(t_info *info)
{
	user_init(info);
	win_init(&(info->win));
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
				mlx_pixel_put(info->win.mlx, info->win.mlx_win, x, y, info->map.ceilling);
			else
				mlx_pixel_put(info->win.mlx, info->win.mlx_win, x, y, info->map.floor);
		}
	}
}

int	img_conv(t_info *info)
{
	int		x;

	paint_floor_ceiling(info);
	printf("posX : %f posY %f\n", info->user.pos_x, info->user.pos_y);
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
			if (info->map.map[info->dda.map_x][info->dda.map_y] == '1' || \
				info->map.map[info->dda.map_x][info->dda.map_y] == ' ')
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
		ver_line(info, x, 65280);
	}
	return (0);
}

// int	check_button(t_info *info)
// {
// 	ft_exit(info);
// 	return (0);
// }

void	move(t_info *info, int x, int y)
{
	if (info->map.map[(int)(info->user.pos_x + x)][(int)(info->user.pos_y + y)] != '1' &&\
		info->map.map[(int)(info->user.pos_x + x)][(int)(info->user.pos_y + y)] != ' ')
	{
		info->user.pos_x += x;
		info->user.pos_y += y;
	}
}

int	check_keypress(int key, t_info *info)
{
	if (key == 13)
		move(info, 1, 0);
	else if (key == 1)
		move(info, -1, 0);
	else if (key == 0)
		move(info, 0, -1);
	else if (key == 2)
		move(info, 0, 1);
	// else if (key == 53)
	// 	ft_exit(info);
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
	//get_texture(info);
	mlx_hook(info->win.mlx_win, 2, 0, check_keypress, info);
	//mlx_hook(info->win.mlx_win, 17, 0, check_button, info);
	mlx_loop_hook(info->win.mlx, img_conv, info);
	printf("show_win 7\n");
	mlx_loop(info->win.mlx);
	printf("show_win 8\n");
}

int parsing(char *argv, t_map *map)
{
	if (path_allocate(map))
		return (1);
	if (check_extention(argv, ".cub"))
		return (ft_error("Invaild extention(cub)"));
	if (get_element(argv, map))
		return (ft_error("**get_element**"));
	ft_printf(*map);
	return (0);
}
void	init_struct(t_info *info)
{
	info->map.direction = 0;
	info->map.row = 0;
}

int main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		init_struct(&info);
		if (parsing(argv[1], &info.map))
			return(1);
		show_win(&info);
	}
	else
		return (ft_error("Invalid number of arguments"));
	return (0);
}
