/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:09:25 by doyun             #+#    #+#             */
/*   Updated: 2021/07/19 16:55:56 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./GNL/get_next_line.h"
# include "./Libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct	s_map
{
	char		**map;
	int			row;
	int			col;
	int			temp_col;
}				t_map;

int	print_error();
int	check_extention(char *argv);
int	check_map_valid(t_map *map_info);
int	check_parm_valid(t_map *map_info);

#endif
