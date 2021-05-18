/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:13:11 by junghan           #+#    #+#             */
/*   Updated: 2021/05/10 16:32:17 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		get_next_line(int fd, char **line);

size_t	ft_strlen2(char *str);
size_t	ft_strlcpy2(char *dest, char *src, size_t destsize);
size_t	ft_strlcat2(char *dest, char *src, size_t size);
char	*ft_strdup2(char *s1);
char	*ft_strjoin2(char *str1, char *str2);

#endif
