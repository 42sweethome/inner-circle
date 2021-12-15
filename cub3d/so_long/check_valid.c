/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:58:39 by sonkang           #+#    #+#             */
/*   Updated: 2021/08/23 00:26:28 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extention(char *argv)
{
	int		len;
	int		ret;

	len = ft_strlen(argv);
	if (len >= 5)
		ret = ft_strncmp(&(argv[len - 4]), ".ber", 4);
	else
		return (-1);
	if (ret != 0)
		return (-1);
	return (0);
}

int	check_map_valid(t_map *m_info)
{
	int	row;
	int	col;

	row = 0;
	col = -1;
	while (++col < m_info->col)
	{
		if (m_info->map[0][col] != '1')
			return (-1);
		if (m_info->map[m_info->row - 1][col] != '1')
			return (-1);
	}
	while (++row < m_info->row - 1)
	{
		if (m_info->map[row][0] != '1')
			return (-1);
		if (m_info->map[row][m_info->col - 1] != '1')
			return (-1);
	}
	return (0);
}

void	get_player_position(int *count, t_map *map, int row, int col)
{
	*count += 1;
	map->player_x = row;
	map->player_y = col;
}

void	get_collect_ea(int	*count, t_map *map)
{
	*count += 1;
	map->collect = *count;
}

int	check_comp_valid(t_map *m_info)
{
	int			row;
	int			col;
	static int	count[3];

	row = -1;
	while (m_info->map[++row])
	{
		col = -1;
		while (m_info->map[row][++col])
		{
			if (m_info->map[row][col] == '0' || m_info->map[row][col] == '1')
				continue ;
			else if (m_info->map[row][col] == 'C')
				get_collect_ea(&count[0], m_info);
			else if (m_info->map[row][col] == 'E')
				count[1]++;
			else if (m_info->map[row][col] == 'P')
				get_player_position(&count[2], m_info, row, col);
			else
				return (-1);
		}
	}
	if (count[0] < 1 || count[1] != 1 || count[2] != 1)
		return (-1);
	return (0);
}
