/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:58:24 by doyun             #+#    #+#             */
/*   Updated: 2021/07/19 17:25:12 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_newline(char *argv, t_map *map_info)
{
	int		ret;
	char	buf;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	map_info->row = 0;
	ret = read(fd, &buf, 1);
	if (buf == '\n')
		map_info->row++;
	while (ret)
	{
		if (buf == '\n')
			map_info->row++;		
		ret = read(fd, &buf, 1);
	}
	close(fd);
	if (ret == -1)
		return (ret);
	return (map_info->row);
}

char		**map_parser(t_map *map_info, char *argv)
{
	int		idx;
	int		fd;
	int		ret;

	map_info->row = get_newline(argv, map_info);
	map_info->map = (char **)ft_calloc(map_info->row + 1, sizeof(char *));
	if (!map_info->map)
		return (NULL);
	idx = -1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = get_next_line(fd, &(map_info->map[++idx]));
	map_info->col = ft_strlen(map_info->map[idx]);
	while (ret)
	{
		ret = get_next_line(fd, &(map_info->map[++idx]));
		map_info->temp_col = ft_strlen(map_info->map[idx]);
		if (idx == map_info->row - 1)
			break ;
		if (map_info->col != map_info->temp_col)
			return (NULL);
	}
	if (ret == -1)
		return (NULL);
	return (map_info->map);
}

int	main(int argc, char **argv)
{
	t_map	map_info;
	int		check;

	if (argc == 2)
	{
		check = check_extention(argv[1]);
		if (check == -1)
			return (print_error());
		map_info.map = map_parser(&map_info, argv[1]);
		if (!map_info.map)
			return (print_error());
		check = check_map_valid(&map_info);
		if (check == -1)
			return (print_error());
		check = check_parm_valid(&map_info);
		if (check == -1)
			return (print_error());				
	}
	else
		return (print_error());
	return (0);

}
