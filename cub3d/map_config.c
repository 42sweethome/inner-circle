/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:17:39 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/24 10:17:40 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	check_element(t_map *map, char c, int idx, int jdx)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (map->direction != 0)
			return (ft_error("player is only one"));
		map->player_x = jdx;
		map->player_y = idx;
		map->direction = map->map[idx][jdx];
		return (0);
	}
	else if (c == '1' || c == ' ' || c == '0')
		return (0);
	return (ft_error("wrong element"));
}

int	row_parsing(t_map *map, int fd)
{
	int		ret;
	int		idx;
	int		jdx;

	idx = -1;
	ret = 1;
	while (ret > 0)
		ret = get_next_line(fd, &(map->map[++idx]));
	if (ret == -1)
		return (ft_error("GNL error"));
	idx = -1;
	while (++idx < map->row)
	{
		jdx = -1;
		while (map->map[idx][++jdx])
		{
			if (check_element(map, map->map[idx][jdx], idx, jdx))
				return (ft_error("**check element**"));
		}
	}
	if (map->direction == 0)
	{
		return (ft_error("no where player"));
	}
	return (0);
}

int	map_parsing(char *argv, t_map *map)
{
	int		fd;
	char	*buf;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_error("Open error"));
	map->map = (char **)ft_calloc(map->row + 1, sizeof(char *));
	if (!map->map)
		return (ft_error("Allocate error"));
	i = -1;
	while (++i < map->cnt_wfc + map->cnt_nl)
	{
		get_next_line(fd, &buf);
		free(buf);
	}
	if (row_parsing(map, fd))
		return (ft_error("**row_parsing**"));
	return (0);
}

int	count_newline(t_map *map, int fd)
{
	int		ret;
	char	*buff;

	while (42)
	{
		ret = get_next_line(fd, &buff);
		if (ret == -1)
			return (ft_error("GNL error"));
		if (*buff != '\0')
		{
			map->row += 1;
			free(buff);
			break ;
		}
		map->cnt_nl += 1;
		free(buff);
	}
	return (0);
}

int	get_newline(t_map *map, int fd)
{
	int		ret;
	char	buf;

	if (count_newline(map, fd))
		return (1);
	ret = read(fd, &buf, 1);
	while (ret > 0)
	{
		if (buf == '\n')
			map->row++;
		ret = read(fd, &buf, 1);
		if (ret == 0)
			map->row += 1;
	}
	close(fd);
	if (ret == -1)
		return (ft_error("Read error"));
	return (0);
}
