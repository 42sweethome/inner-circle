/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:31:49 by daekim            #+#    #+#             */
/*   Updated: 2021/02/02 14:25:58 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_tenlen(ssize_t n, t_cond *con)
{
	int		len;
	ssize_t num;

	len = 0;
	num = n;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	if (con->width > len && num < 0 && con->zero == 1 && con->dot == 0)
		len = con->width;
	if (con->pre >= len && num < 0 && con->minus_pre == 0)
		len = con->pre + 1;
	else if (con->pre > len && con->minus_pre == 0)
		len = con->pre;
	return (len);
}

char		*ten_ten(ssize_t n, t_cond *con)
{
	char	*output;
	int		len;
	int		i;
	ssize_t	num;

	len = ft_tenlen(n, con);
	if (!(output = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = len;
	num = n;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		output[--i] = (n % 10) + '0';
		n /= 10;
	}
	while (i-- >= 0)
		output[i] = '0';
	if (num < 0)
		output[0] = '-';
	return (output);
}

int			ft_hexlen(ssize_t n, t_cond *con)
{
	int		len;
	ssize_t	num;

	len = 0;
	num = n;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	if (len < con->pre && con->minus_pre == 0)
		len = con->pre;
	return (len);
}

void		put_zero(t_cond *con, char *output, int i)
{
	while (i > 1)
	{
		if (con->poi == 1 && con->dot == 1 && con->pre == 0)
			break ;
		output[i--] = '0';
	}
}

char		*ten_hex(ssize_t n, t_cond *con)
{
	char	*output;
	int		len;
	int		i;

	len = ft_hexlen(n, con);
	if (!(output = (char *)ft_calloc((len + 3), sizeof(char))))
		return (0);
	i = len + 1;
	if (n == 0 && con->dot == 1 && con->pre != 0)
		output[2] = '0';
	while (n > 0)
	{
		if ((n % 16) < 10)
			output[i--] = (n % 16) + '0';
		else
			output[i--] = (n % 16) + 'a' - 10;
		n /= 16;
	}
	put_zero(con, output, i);
	output[0] = '0';
	output[1] = 'x';
	return (output);
}
