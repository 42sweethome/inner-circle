/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poi_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:39:32 by daekim            #+#    #+#             */
/*   Updated: 2021/02/02 12:34:52 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		opt_cp(t_cond *con)
{
	if (con->p_star == 1 && con->width < con->pre)
	{
		con->minus_pre = 0;
		con->pre = con->width;
	}
}

int			prin(char *str, int *ret)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
		(*ret)++;
	}
	return (*ret);
}

int			print_poi(char *str, t_cond *con, int len, int *ret)
{
	int		f_len;

	opt_cp(con);
	if (con->minus == 1 || con->minus_pre == 1)
		*ret = prin(str, ret);
	if (con->minus_pre == 0)
		f_len = con->width - len;
	else
		f_len = con->pre - len;
	while (f_len-- > 0)
	{
		if (con->zero == 1 && con->minus == 0 && con->width < con->pre)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*ret)++;
	}
	if (con->minus == 0 && con->minus_pre == 0)
		*ret = prin(str, ret);
	return (*ret);
}

int			print_c(char c, t_cond *con, int *ret)
{
	int		len;

	opt_cp(con);
	if (con->minus == 1 || con->minus_pre == 1)
		write(1, &c, 1);
	if (con->minus_pre == 0)
		len = con->width - 1;
	else
		len = con->pre - 1;
	while (len-- > 0)
	{
		if (con->zero == 1 && con->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*ret)++;
	}
	if (con->minus == 0 && con->minus_pre == 0)
		write(1, &c, 1);
	(*ret)++;
	return (*ret);
}
