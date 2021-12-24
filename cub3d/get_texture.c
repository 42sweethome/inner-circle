/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:17:17 by sonkang           #+#    #+#             */
/*   Updated: 2021/12/24 10:17:18 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_form(t_map *map, char **split)
{
	if (split[0] == 0 || split[1] == 0 || split[2] != 0)
		return (ft_error("Wrong information"));
	if (get_ele(map, split))
		return (ft_error("wrong input wfc"));
	return (0);
}

int	check_texture(t_map *map)
{
	int		i;

	i = -1;
	while (++i < 6)
	{
		if (map->wfc[i] == 0)
			break ;
		if (map->wfc[i] > 1)
			return (ft_error("wfc is over"));
	}
	if (i != 6)
		return (1);
	return (0);
}

int	get_path_color(t_map *map, int fd)
{
	int		ret;
	char	*buf;
	char	**split;

	while (check_texture(map))
	{
		map->cnt_wfc++;
		ret = get_next_line(fd, &buf);
		if (ret == -1)
			return (ft_error("GNL error"));
		if (!*buf)
		{
			free(buf);
			continue ;
		}
		split = ft_split(buf, ' ');
		free(buf);
		if (check_form(map, split))
			return (ft_error("**check_form**"));
		ft_free(split);
	}
	return (0);
}
