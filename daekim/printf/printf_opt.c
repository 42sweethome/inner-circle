/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:25:50 by daekim            #+#    #+#             */
/*   Updated: 2021/02/01 18:37:55 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		opt_pre(const char *str, va_list ap, int *i, t_cond *con)
{
	con->dot = 1;
	(*i)++;
	if (str[*i] == '-')
	{
		con->minus_pre = 1;
		(*i)++;
	}
	if (str[*i] == '*')
	{
		con->p_star = 1;
		con->pre = va_arg(ap, int);
		(*i)++;
		if (con->pre < 0)
		{
			con->pre = 0;
			con->dot = 0;
		}
	}
	else
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			con->pre *= 10;
			con->pre += str[*i] - '0';
			(*i)++;
		}
}

void		opt_width(const char *str, va_list ap, int *i, t_cond *con)
{
	if (str[*i] == '*')
	{
		con->width = va_arg(ap, int);
		(*i)++;
		con->w_star = 1;
		if (con->width < 0)
		{
			con->minus = 1;
			con->width *= -1;
		}
	}
	else
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			con->width *= 10;
			con->width += str[*i] - '0';
			(*i)++;
		}
}

void		ft_opt(const char *str, va_list ap, int *i, t_cond *con)
{
	while (str[*i] == '-' || str[*i] == '0')
	{
		if (str[*i] == '-')
			con->minus = 1;
		else if (str[*i] == '0')
			con->zero = 1;
		(*i)++;
	}
	opt_width(str, ap, i, con);
	if (str[*i] == '.')
		opt_pre(str, ap, i, con);
	if (con->minus == 1 && con->zero == 1)
		con->zero = 0;
}
