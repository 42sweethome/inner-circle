/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:17:48 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/24 10:17:48 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extention(char *argv, char *str)
{
	int		len;
	int		ret;

	len = ft_strlen(argv);
	if (len >= 5)
		ret = ft_strncmp(&(argv[len - 4]), str, 4);
	else
		return (1);
	if (ret != 0)
		return (1);
	return (0);
}

void	ft_exit(t_info *info)
{
	mlx_destroy_window(info->win.mlx, info->win.mlx_win);
	mlx_destroy_image(info->win.mlx, info->fimg.img);
	exit(0);
}

void	ft_free(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
}

int	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(0);
}
