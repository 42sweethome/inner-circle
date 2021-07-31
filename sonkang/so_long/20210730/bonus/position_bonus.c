/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:58:39 by sonkang           #+#    #+#             */
/*   Updated: 2021/07/31 15:23:04 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_position(int *count, t_map *map, int row, int col)
{
	*count += 1;
	map->player_x = col;
	map->player_y = row;
}

void	get_villian_position(t_map *map, int row, int col)
{
	map->v_x = col;
	map->v_y = row;
}