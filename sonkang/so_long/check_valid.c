/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:58:39 by doyun             #+#    #+#             */
/*   Updated: 2021/07/19 17:24:47 by doyun            ###   ########.fr       */
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

int	check_parm_valid(t_map *map_info)
{
	int			row;
	int			col;
	static int	count[3];

	row = -1;
	while (map_info->map[++row])
	{
		col = -1;
		while (map_info->map[row][++col])
		{
			if (map_info->map[row][col] == '0' || map_info->map[row][col] == '1')
				continue ;
			else if (map_info->map[row][col] == 'C')
				count[0]++;
			else if (map_info->map[row][col] == 'E')
				count[1]++;
			else if (map_info->map[row][col] == 'P')
				count[2]++;
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
	int row;
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
