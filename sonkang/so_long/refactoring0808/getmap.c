/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by sonkang           #+#    #+#             */
/*   Updated: 2021/08/11 22:53:32 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int i)
{
	printf("Error\n");
	if (i == 0)
		perror("number of arguments isn't right!\n");
	if (i == 1)
		perror("Invalid extension\n");
	if (i == 2)
		perror(NULL);
	if (i == 3)
		printf("Map parsing was not done properly!\n");
	if (i == 4)
		printf("The map is not surrounded by walls!\n");
	if (i == 5)
	{
		printf("The map must be composed of only 5 possible characters.\n");
		printf("And map must have at least one exit, one collectible, ");
		printf("and one starting position!\n");
	}
	if (i == 6)
		printf("size of map is too big!\n");
	exit(1);
}

void	show_win(t_info *info)
{
	int	user_win[2];
	//int	x;

	info->win.mlx = mlx_init();
	mlx_get_screen_size(info->win.mlx, &user_win[0], &user_win[1]);
	if (!(user_win[0] >= 64 * info->map.col && user_win[1] >= \
		64 * info->map.row))
		print_error(6);
	info->win.mlx_win = mlx_new_window(info->win.mlx, 64 * info->map.col, \
	64 * info->map.row, "Bubble Bobble");
	printf("how many walk : 0\n");
	info->fimg.img = mlx_new_image(info->win.mlx, 64 * info->map.col, \
	64 * info->map.row);
	info->fimg.addr = (unsigned int *)mlx_get_data_addr(info->fimg.img, \
	&info->fimg.bits_per_pixel, &info->fimg.line_length, &info->fimg.endian);
	get_texture(info);
	mlx_hook(info->win.mlx_win, 2, 0, check_keypress, info);
	mlx_hook(info->win.mlx_win, 17, 0, check_button, info);
	mlx_loop_hook(info->win.mlx, img_conv, info);
	mlx_loop(info->win.mlx);
}

int	main(int argc, char **argv)
{
	t_info		info;

	if (argc == 2)
	{
		parsing(&info, argv[1]);
		show_win(&info);
	}
	else
		print_error(0);
	return (0);
}
