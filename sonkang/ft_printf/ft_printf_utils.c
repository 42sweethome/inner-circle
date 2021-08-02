/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:48:39 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/19 18:48:41 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(unsigned char*)s = 0;
		s++;
		n--;
	}
	return ;
}

void				*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	int				i;

	i = 0;
	if (!(ptr = malloc(size * count)))
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char				*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1);
	if (!(ptr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	return (ptr);
}

size_t				ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

int					ft_write(int ret, char *s)
{
	int				i;

	i = 0;
	if (ret <= 0)
		ret = 0;
	while (i++ < ret)
		write(1, s, 1);
	return (ret);
}
