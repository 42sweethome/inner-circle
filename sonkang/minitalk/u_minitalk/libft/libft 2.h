/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:43:05 by sonkang           #+#    #+#             */
/*   Updated: 2021/07/19 23:34:29 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(char *s);
size_t				ft_strlcpy(char *dest, char *src, size_t dstsize);
size_t				ft_strlcat(char *dest, char *src, size_t dstsize);
int					ft_atoi(char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_itoa(int n);

#endif
