/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:16:57 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/24 10:18:49 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(char c)
{
	if (c == '1' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	check_wall_from_back(char *str, int gap)
{
	int		len;
	int		idx;

	len = ft_strlen(str);
	idx = -1;
	while (++idx < gap)
	{
		if (!is_wall(str[len - idx - 1]))
			return (ft_error("wall have hole"));
	}
	return (0);
}

int	check_map_side_valid(t_map *map)
{
	int		i;
	int		len1;
	int		len2;

	i = 0;
	while (i < map->row)
	{
		if (*(map->map[i]) && !is_wall(*(map->map[i])))
			return (ft_error("is not wall"));
		len1 = ft_strlen(map->map[i]);
		if (i == map->row - 1)
			return (0);
		len2 = ft_strlen(map->map[i + 1]);
		if (len1 > len2)
			if (check_wall_from_back(map->map[i], len1 - len2))
				break ;
		if (len1 < len2)
			if (check_wall_from_back(map->map[i + 1], len2 - len1))
				break ;
		i++;
	}
	return (ft_error("map back is hole"));
}

int	check_map_valid(t_map *map)
{
	int		j;

	j = 0;
	while (is_wall(map->map[0][j]))
		j++;
	if (map->map[0][j] != '\0')
		return (ft_error("wall have hole"));
	j = 0;
	while (is_wall(map->map[map->row - 1][j]))
		j++;
	if (map->map[map->row - 1][j] != '\0')
		return (ft_error("wall have hole"));
	return (check_map_side_valid(map));
}
