/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:58:19 by sonkang           #+#    #+#             */
/*   Updated: 2021/08/02 23:05:34 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_newline(char *content)
{
	int		i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	split_line(char **content, int i, char **line)
{
	char	*temp;

	(*content)[i] = '\0';
	*line = ft_strdup(*content);
	if (*content + i + 1)
	{
		temp = ft_strdup(*content + i + 1);
		free(*content);
		*content = temp;
		return (1);
	}
	free(*content);
	*content = 0;
	return (1);
}

int	return_all(char **content, char **line, int rd_size)
{
	int		cut_idx;

	if (rd_size < 0)
		return (-1);
	cut_idx = check_newline(*content);
	if (*content && 0 <= cut_idx)
		return (split_line(content, cut_idx, line));
	if (*content)
	{
		*line = ft_strdup(*content);
		free(*content);
		*content = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			rd_size;
	int			cut_idx;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	static char	*content[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || line == 0 || fd < 0)
		return (-1);
	rd_size = read(fd, buf, BUFFER_SIZE);
	while (0 < rd_size)
	{
		buf[rd_size] = '\0';
		temp = ft_strjoin(content[fd], buf);
		free(content[fd]);
		content[fd] = temp;
		cut_idx = check_newline(content[fd]);
		if (0 <= cut_idx)
			return (split_line(&content[fd], cut_idx, line));
		rd_size = read(fd, buf, BUFFER_SIZE);
	}
	return (return_all(&content[fd], line, rd_size));
}
