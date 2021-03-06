/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by doyun             #+#    #+#             */
/*   Updated: 2021/07/26 14:29:00 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
	return (-1);
}

void	show_win(t_info *info)
{
	int	user_win[2];

	info->win.mlx = mlx_init();
	mlx_get_screen_size(info->win.mlx, &user_win[0], &user_win[1]);
	if (!(user_win[0] >= 16 * info->map.col && user_win[1] >= \
		16 * info->map.row && info->map.col % 4 == 0))
		print_error();
	info->win.mlx_win = mlx_new_window(info->win.mlx, 16 * info->map.col, \
	16 * info->map.row, "Noleogaza!");
	printf("how many walk : 0\n");
	info->fimg.img = mlx_new_image(info->win.mlx, 16 * info->map.col, \
	16 * info->map.row);
	info->fimg.addr = (int *)mlx_get_data_addr(info->fimg.img, \
	&info->fimg.bits_per_pixel, &info->fimg.line_length, &info->fimg.endian);
	mlx_hook(info->win.mlx_win, 2, 0, check_keypress, info);
	mlx_hook(info->win.mlx_win, 17, 0, check_button, info);
	mlx_loop_hook(info->win.mlx, img_conv, info);
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
