/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:39:32 by daekim            #+#    #+#             */
/*   Updated: 2021/02/02 13:04:46 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_morz(t_cond *con, int len, int *ret)
{
	int		l;

	if (con->minus_pre == 0)
	{
		l = con->width - len;
		if (con->dot == 1 && con->pre == 0)
			l = con->width;
	}
	else
		l = con->width;
	while (l-- > 0)
	{
		if (con->zero == 1 && con->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*ret)++;
	}
	return (*ret);
}

int			s_prin(char *str, t_cond *con, int len, int *ret)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (con->dot == 1 && con->pre == 0)
			break ;
		write(1, &str[i++], 1);
		(*ret)++;
	}
	return (*ret);
}

int			print_str(char *str, t_cond *con, int len, int *ret)
{
	int		i;

	i = 0;
	if (con->minus_pre == 1)
	{
		if (con->p_star == 1 && con->width < con->pre)
		{
			con->dot = 0;
			con->minus_pre = 0;
			con->pre = con->width;
		}
		else
			con->width = con->pre;
		con->pre = 0;
	}
	if ((con->minus == 1 || con->minus_pre == 1))
		*ret = s_prin(str, con, len, ret);
	*ret = print_morz(con, len, ret);
	if (con->minus == 0 && con->minus_pre == 0)
		*ret = s_prin(str, con, len, ret);
	return (*ret);
}
