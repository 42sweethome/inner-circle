/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim </var/mail/daekim>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:08:04 by daekim            #+#    #+#             */
/*   Updated: 2021/01/20 14:48:55 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int			main(int ac, char **av)
{
	int		fd;
	char	*line;

	line = 0;
	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
		printf("((%s))\n", line);
	printf("((%s))\n", line);
	close(fd);
	return (0);
}
