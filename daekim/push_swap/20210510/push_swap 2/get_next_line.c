/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:49:20 by junghan           #+#    #+#             */
/*   Updated: 2021/05/10 16:32:39 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_nl(char *save, char n)
{
	int		idx;

	idx = 0;
	while (save[idx])
	{
		if (save[idx] == n)
			return (idx);
		idx++;
	}
	return (-1);
}

int		cut_string(char **save, char **line, int cut_point, char *buf)
{
	char	*tmp;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	(*save)[cut_point] = '\0';
	if (!(*line = ft_strdup2(*save)) ||
				!(tmp = ft_strdup2((*save) + cut_point + 1)))
	{
		free(*save);
		*save = 0;
		return (-1);
	}
	free(*save);
	*save = tmp;
	return (1);
}

int		put_all(char **save, char **line, ssize_t offset, char *buf)
{
	int		cut_point;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	if (offset < 0)
		return (-1);
	if (*save && ((cut_point = find_nl(*save, '\n')) >= 0))
		return (cut_string(save, line, cut_point, buf));
	if (*save)
	{
		*line = *save;
		*save = 0;
	}
	else
	{
		if (!(*line = ft_strdup2("")))
			return (-1);
	}
	return (0);
}

char	*set_save(char *save, char *buf)
{
	char	*tmp;

	if (save)
		tmp = ft_strjoin2(save, buf);
	else
		tmp = ft_strdup2(buf);
	if (tmp == 0)
	{
		if (save)
		{
			free(save);
			save = 0;
		}
		free(buf);
		buf = 0;
		return (NULL);
	}
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	ssize_t			offset;
	int				cut_point;
	static char		*save[OPEN_MAX];
	char			*tmp;
	char			*buf;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((offset = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[offset] = '\0';
		if (!(tmp = set_save(save[fd], buf)))
			return (-1);
		if (save[fd])
			free(save[fd]);
		save[fd] = tmp;
		if ((cut_point = find_nl(save[fd], '\n')) >= 0)
			return (cut_string(&save[fd], line, cut_point, buf));
	}
	return (put_all(&save[fd], line, offset, buf));
}
