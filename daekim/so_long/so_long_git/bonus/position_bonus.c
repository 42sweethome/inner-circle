/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:47:25 by daekim            #+#    #+#             */
/*   Updated: 2021/09/04 11:47:27 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_position(int *count, t_map *map, int row, int col)
{
	*count += 1;
	map->player_x = row;
	map->player_y = col;
}

void	get_villian_position(t_map *map, int row, int col)
{
	map->v_x = row;
	map->v_y = col;
}
