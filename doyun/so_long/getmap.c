/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by doyun             #+#    #+#             */
/*   Updated: 2021/07/21 18:07:37 by doyun            ###   ########.fr       */
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
		return (0);
}

int		draw(t_info *info, int i, int j, t_data tex)
{
	int		width;
	int		height;

	width = -1;
	height = -1;
	while (++height < info->block.height)
	{
		while (++width < info->block.width)
		{
			info->fimg.addr = 
			mlx_pixel_put(info->win.mlx, info->win.mlx_win, info->block.width * j + width, info->block.height * i + height, color);
		}
		width = -1;
	}
	return (0);
}

int		img_conv(t_info *info)
{
	int		i;
	int		j;

	info->block.width = 1024 / info->map.col;
	info->block.height = 768 / info->map.row;
	i = -1;
	j = -1;
//	printf("row : %d, col :%d\n", info->map.row, info->map.col);
	while (++i < info->map.row)
	{
		while (++j < info->map.col)
		{
//			printf("map : %c\n", info->map.map[i][j]);
			if (info->map.map[i][j] == '0')
				draw(info, i, j, info->tex[0]);
			else if (info->map.map[i][j] == '1')
				draw(info, i, j, info->tex[1]);
			else if (info->map.map[i][j] == 'C')
				draw(info, i, j, info->tex[2]);
			else if (info->map.map[i][j] == 'E')
				draw(info, i, j, info->tex[3]);
			else if (info->map.map[i][j] == 'P')
				draw(info, i, j, info->tex[4]);
		}
		j = -1;
	}
	return (0);
}

int		show_snoop(t_info *info)
{
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
	//	exit();
	}
	else
		printf("keep going!\n");
}

void	move(t_info *info, int x, int y)
{
	if (info->map.player_y > 0 && info->map.player_y < info->block.height)
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
			}
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
	return (0);	
}

void	get_texture(t_info *info)
{
	info->tex[0].img = mlx_xpm_file_to_image(info->mlx, "./texture/grass.xpm", &info->tex[0].image_width, &info->tex[0].image_height);
	info->tex[1].img = mlx_xpm_file_to_image(info->mlx, "./texture/grass.xpm", &info->tex[1].image_width, &info->tex[1].image_height);
	info->tex[2].img = mlx_xpm_file_to_image(info->mlx, "./texture/mush.xpm", &info->tex[2].image_width, &info->tex[2].image_height);
	info->tex[3].img = mlx_xpm_file_to_image(info->mlx, "./texture/grass.xpm", &info->tex[3].image_width, &info->tex[3].image_height);
	info->tex[4].img = mlx_xpm_file_to_image(info->mlx, "./texture/grass.xpm", &info->tex[4].image_width, &info->tex[4].image_height);
	info->tex[0].addr = mlx_get_data_addr(info->tex[0].img, &info->tex[0].bit_per_pixel, &info->tex[0].line_lengh, &info->tex[0].endian);
	info->tex[1].addr = mlx_get_data_addr(info->tex[1].img, &info->tex[1].bit_per_pixel, &info->tex[1].line_lengh, &info->tex[1].endian);
	info->tex[2].addr = mlx_get_data_addr(info->tex[2].img, &info->tex[2].bit_per_pixel, &info->tex[2].line_lengh, &info->tex[2].endian);
	info->tex[3].addr = mlx_get_data_addr(info->tex[3].img, &info->tex[3].bit_per_pixel, &info->tex[3].line_lengh, &info->tex[3].endian);
	info->tex[4].addr = mlx_get_data_addr(info->tex[4].img, &info->tex[4].bit_per_pixel, &info->tex[4].line_lengh, &info->tex[4].endian);
}

void	show_win(t_info *info)
{
	info->win.mlx = mlx_init();
	info->win.mlx_win = mlx_new_window(info->win.mlx, 1024, 768, "Hello world!");
	info->fimg.img = mlx_new_image(info->mlx, 1024, 768);
	info->fimg.addr = mlx_get_data_addr(info->fimg.img, &info->fimg.bit_per_pixel, &info->fimg.line_lengh, &info->fimg.endian);
	get_texture(info);
	mlx_loop_hook(info->win.mlx, show_snoop, info);
	mlx_hook(info->win.mlx_win, 2, 1, check_keypress, info);
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
