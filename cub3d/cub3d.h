/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:17:10 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/24 10:17:10 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./GNL/get_next_line.h"
# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "parsing.h"
# include "graphic.h"

//utils.c
int		check_extention(char *argv, char *str);
int		ft_error(char *str);
void	ft_free(char **str);
void	ft_exit(t_info *info);

//graphic_init.c
void	grap_init(t_info *info);

//button_key.c
int		check_keypress(int key, t_info *info);
int		check_button(t_info *info);

//image_conversion.c
int		img_conv(t_info *info);

//image_conversion2.c
void	affine_texture_mapping(t_info *info, int x);
void	draw(t_info *info);

//get_texture.c & get_texture2.c
int		get_path_color(t_map *map, int fd);
int		get_ele(t_map *map, char **split);

#endif
