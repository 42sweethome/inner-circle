#include "cub3d.h"

void	get_texture(t_info *info)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		info->tex[i].img = mlx_xpm_file_to_image(info->win.mlx, \
		info->map.path[i], &info->tex[i].img_width, &info->tex[i].img_height);
		info->tex[i].addr = (unsigned int *)mlx_get_data_addr \
		(info->tex[i].img, &info->tex[i].bits_per_pixel, \
		&info->tex[i].line_length, &info->tex[i].endian);
	}
}

void	show_win(t_info *info)
{
	grap_init(info);
	info->win.mlx = mlx_init();
	info->win.mlx_win = mlx_new_window(info->win.mlx, \
		info->win.win_w, info->win.win_h, "cub3D");
	info->fimg.img = mlx_new_image(info->win.mlx, \
		info->win.win_w, info->win.win_h);
	info->fimg.addr = (unsigned int *)mlx_get_data_addr(info->fimg.img, \
		&info->fimg.bits_per_pixel, &info->fimg.line_length, \
		&info->fimg.endian);
	get_texture(info);
	mlx_hook(info->win.mlx_win, 2, 0, check_keypress, info);
	mlx_hook(info->win.mlx_win, 17, 0, check_button, info);
	mlx_loop_hook(info->win.mlx, img_conv, info);
	mlx_loop(info->win.mlx);
}

int	parsing(char *argv, t_map *map)
{
	if (path_allocate(map))
		return (1);
	if (check_extention(argv, ".cub"))
		return (ft_error("Invaild extention(cub)"));
	if (get_element(argv, map))
		return (1);
	return (0);
}

void	init_struct(t_info *info)
{
	int		i;

	i = -1;
	while (++i < 6)
		info->map.wfc[i] = 0;
	info->map.cnt_wfc = 0;
	info->map.direction = 0;
	info->map.row = 0;
	info->map.cnt_nl = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		init_struct(&info);
		if (parsing(argv[1], &info.map))
			return (1);
		show_win(&info);
	}
	else
		return (ft_error("Invalid number of arguments"));
	return (0);
}
