/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42.fr>                +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:58:39 by sonkang             #+#    #+#           */
/*   Updated: 2021/07/30 10:26:01 by sonkang            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	get_collect_ea(int *count, t_map *map)
{
	*count += 1;
	map->collect = *count;
	map->v_f = *count;
}

int	check_parm_valid(t_map *m_info)
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

int	check_map_valid(t_map *map_info)
{
	int	row;
	int	col;

	row = 0;
	col = -1;
	while ((map_info->map)[row][++col])
	{
		if (map_info->map[row][col] != '1')
			return (-1);
		if (map_info->map[map_info->row - 1][col] != '1')
			return (-1);
	}
	while (++row < map_info->row - 1)
	{
		if (map_info->map[row][0] != '1' || map_info->map[row][col - 1] != '1')
			return (-1);
	}
	return (0);
}
