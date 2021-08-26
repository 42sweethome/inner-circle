/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:56:15 by daekim            #+#    #+#             */
/*   Updated: 2021/01/01 22:39:48 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			power(int i)
{
	int				a;

	a = 1;
	while (i)
	{
		a = a * 10;
		i--;
	}
	return (a);
}

void				ft_putnbr_fd(int n, int fd)
{
	int				i;
	long long int	num;
	char			c;

	i = 0;
	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	while (n < -9 || n > 9)
	{
		n = n / 10;
		i++;
	}
	while (i)
	{
		c = (num / power(i)) + 48;
		write(fd, &c, 1);
		num = num % power(i);
		i--;
	}
	c = num % 10 + 48;
	write(fd, &c, 1);
}
