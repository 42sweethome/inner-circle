/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by doyun             #+#    #+#             */
/*   Updated: 2021/07/23 16:40:59 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int	get_newline(char *argv, t_map *map_info)
{
	int		ret;
	char	buf;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	map_info->row = 0;
	ret = read(fd, &buf, 1);
	if (buf == '\n')
		map_info->row++;
	while (ret)
	{
		if (buf == '\n')
			map_info->row++;	
		ret = read(fd, &buf, 1);
	}
	close(fd);
	if (ret == -1)
		return (ret);
	return (map_info->row);
}

char		**map_parser(t_map *map_info, char *argv)
{
	int		idx;
	int		fd;
	int		ret;

	map_info->row = get_newline(argv, map_info);
	map_info->map = (char **)ft_calloc(map_info->row + 1, sizeof(char *));
	if (!map_info->map)
		return (NULL);
	idx = -1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = get_next_line(fd, &(map_info->map[++idx]));
	map_info->col = ft_strlen(map_info->map[idx]);
	while (ret)
	{
		ret = get_next_line(fd, &(map_info->map[++idx]));
		map_info->temp_col = ft_strlen(map_info->map[idx]);
		if (idx == map_info->row - 1)
			break ;
		if (map_info->col != map_info->temp_col)
			return (NULL);
	}
	if (ret == -1)
		return (NULL);
	return (map_info->map);
}
int		parsing(t_info *info, char *argv)
{
	int		check;

	check = check_extention(argv);
	if (check == -1)
		return (print_error());
	info->map.map = map_parser(&info->map, argv);
	if (!info->map.map)
		return (print_error());
	check = check_map_valid(&info->map);
	if (check == -1)
		return (print_error());
	check = check_parm_valid(&info->map);
	if (check == -1)
		return (print_error());
	info->map.walk = 0;
	printf("how many walk : 0\n");
	return (0);
}

int		draw(t_info *info, int y, int x, t_data tex)
{
	int		width;
	int		height;

	height = -1;
	while (++height < tex.img_height)
	{
		width = -1;
		while (++width < tex.img_width)
		{
			//printf("%d\n",tex.img_width * (x + info->map.col * (height + tex.img_height * y)) + width);
			info->fimg.addr[/*tex.img_width * tex.img_height * (x + info->map.col * y) + (height * tex.img_width+ width)*/tex.img_width * (x + info->map.col * (height + tex.img_height * y)) + width] = tex.addr[height * tex.img_width * 4 + width]; //+ (height * tex.img_width + width * (tex.bits_per_pixel / 8));
		}
		//printf("%d %d\n", width, height);
	}
	return (0);
}

int		img_conv(t_info *info)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	while (++y < info->map.row)
	{
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
		x = -1;
	}
	mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, info->fimg.img, 0, 0);
	return (0);
}
void	get_texture(t_info *info)
{
	info->tex[0].img = mlx_xpm_file_to_image(info->win.mlx, "./texture/grass2.xpm", &info->tex[0].img_width, &info->tex[0].img_height);
	info->tex[1].img = mlx_xpm_file_to_image(info->win.mlx, "./texture/grass.xpm", &info->tex[1].img_width, &info->tex[1].img_height);
	info->tex[2].img = mlx_xpm_file_to_image(info->win.mlx, "./texture/cake.xpm", &info->tex[2].img_width, &info->tex[2].img_height);
	info->tex[3].img = mlx_xpm_file_to_image(info->win.mlx, "./texture/ghost.xpm", &info->tex[3].img_width, &info->tex[3].img_height);
	info->tex[4].img = mlx_xpm_file_to_image(info->win.mlx, "./texture/char.xpm", &info->tex[4].img_width, &info->tex[4].img_height);
	info->tex[0].addr = (int *)mlx_get_data_addr(info->tex[0].img, &info->tex[0].bits_per_pixel, &info->tex[0].line_length, &info->tex[0].endian);
	info->tex[1].addr = (int *)mlx_get_data_addr(info->tex[1].img, &info->tex[1].bits_per_pixel, &info->tex[1].line_length, &info->tex[1].endian);
	info->tex[2].addr = (int *)mlx_get_data_addr(info->tex[2].img, &info->tex[2].bits_per_pixel, &info->tex[2].line_length, &info->tex[2].endian);
	info->tex[3].addr = (int *)mlx_get_data_addr(info->tex[3].img, &info->tex[3].bits_per_pixel, &info->tex[3].line_length, &info->tex[3].endian);
	info->tex[4].addr = (int *)mlx_get_data_addr(info->tex[4].img, &info->tex[4].bits_per_pixel, &info->tex[4].line_length, &info->tex[4].endian);
}

int		show_snoop(t_info *info)
{
	get_texture(info);
	img_conv(info);
	/*info->data.img = mlx_xpm_file_to_image(info->win.mlx, "./snoopy.xpm", &(info->data.img_width), &(info->data.img_height));
	  info->data.addr = mlx_get_data_addr(info->data.img, &(info->data.bits_per_pixel),&(info->data.line_length), &(info->data.endian));
	  mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, info->data.img, 0, 0);*/
	return (0);
}

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

void	move(t_info *info, int x, int y)
{
	if (info->map.map[info->map.player_y + y][info->map.player_x + x] != '1')
	{
		if (info->map.map[info->map.player_y + y][info->map.player_x + x] == 'E')
			ft_exit(info);
		if (info->map.map[info->map.player_y + y][info->map.player_x + x] == 'C')
			info->map.collect -= 1;
		if (!(info->map.map[info->map.player_y + y][info->map.player_x + x] == 'E' && info->map.collect != 0))
		{
			info->map.map[info->map.player_y][info->map.player_x] = '0';
			info->map.map[info->map.player_y += y][info->map.player_x += x] = 'P';
			printf("how many walk : %d\n", ++info->map.walk);
		}
	}
}

int	check_keypress(int key, t_info *info)
{
	if (key == KEY_W)
		move(info, 0, -1);
	else if (key == KEY_S)
		move(info, 0 , 1);
	else if (key == KEY_A)
		move(info, -1, 0);
	else if (key == KEY_D)
		move(info, 1, 0);
	else if (key == KEY_ESC)
		exit(0);
	printf("%d\n",key);
	return (0);	
}

int	check_button()
{
	exit(0);
	return (0);
}
void	show_win(t_info *info)
{
	info->win.mlx = mlx_init();

	info->win.mlx_win = mlx_new_window(info->win.mlx, 16 * info->map.col, 16 * info->map.row, "Hello world!");
	info->fimg.img = mlx_new_image(info->win.mlx, 16 * info->map.col, 16 * info->map.row);
	info->fimg.addr = (int *)mlx_get_data_addr(info->fimg.img, &info->fimg.bits_per_pixel, &info->fimg.line_length, &info->fimg.endian);
	//get_texture(info);
	mlx_hook(info->win.mlx_win, 2, 0, check_keypress, info);
	mlx_hook(info->win.mlx_win, 17, 0, check_button, info);
	mlx_loop_hook(info->win.mlx, show_snoop, info);
	mlx_loop(info->win.mlx);
}

int	main(int argc, char **argv)
{
	t_info		info;
	int			check;

	if (argc == 2)
	{
		check = parsing(&info, argv[1]);
		if (check == -1)
			return (-1);
		show_win(&info);
	}
	else
		return (print_error());
	return (0);
}
