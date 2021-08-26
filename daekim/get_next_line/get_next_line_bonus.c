/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:14:27 by daekim            #+#    #+#             */
/*   Updated: 2021/01/20 15:50:38 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				ft_find(char *newline, char c)
{
	int			i;

	i = 0;
	while (newline[i])
	{
		if (newline[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				in_line(char **newline, char **line, int i)
{
	char		*ret;

	(*newline)[i] = 0;
	if (!(*line = ft_strdup(*newline)))
		return (-1);
	if (!(ret = ft_strdup(*newline + i + 1)))
		return (-1);
	free(*newline);
	*newline = ret;
	return (1);
}

int				backup(char **newline, char **line, int r)
{
	int			new_idx;

	if (r < 0)
		return (-1);
	if (*newline == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((new_idx = ft_find(*newline, '\n')) >= 0)
		return (in_line(newline, line, new_idx));
	if (!(*line = ft_strdup(*newline)))
		return (-1);
	free(*newline);
	*newline = 0;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*newline[OPEN_MAX];
	char		*buf;
	char		*temp;
	int			rd_size;
	int			new_idx;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		if (!(temp = ft_strjoin(newline[fd], buf)))
			return (-1);
		free(newline[fd]);
		newline[fd] = temp;
		if ((new_idx = ft_find(newline[fd], '\n')) >= 0)
		{
			free(buf);
			return (in_line(&newline[fd], line, new_idx));
		}
	}
	free(buf);
	return (backup(&newline[fd], line, rd_size));
}
