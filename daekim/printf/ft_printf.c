/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:40:45 by daekim            #+#    #+#             */
/*   Updated: 2021/02/02 13:03:41 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_struct(t_cond *con)
{
	con->minus = 0;
	con->zero = 0;
	con->width = 0;
	con->w_star = 0;
	con->dot = 0;
	con->pre = 0;
	con->p_star = 0;
	con->minus_pre = 0;
	con->poi = 0;
}

int			ft_div(va_list ap, char c, t_cond *con)
{
	int ret;

	ret = 0;
	if (c == 'c')
		ret = put_chr(ap, con);
	else if (c == 's')
		ret = put_str(ap, con);
	else if (c == 'p')
		ret = put_poi(ap, con);
	else if (c == 'd' || c == 'i')
		ret = put_dig(ap, con);
	else if (c == 'u')
		ret = put_uni(ap, con);
	else if (c == 'x' || c == 'X')
		ret = put_hex(ap, c, con);
	else if (c == '%')
		ret = put_per('%', con);
	return (ret);
}

int			check_cond(const char *str, va_list ap, int *i)
{
	int		idx;
	int		ret;
	t_cond	con;

	idx = *i;
	ret = 0;
	while (str[++idx])
	{
		ft_struct(&con);
		ft_opt(str, ap, &idx, &con);
		if (str[idx])
		{
			ret = ft_div(ap, str[idx], &con);
			if (ret == -1)
				return (ret);
			break ;
		}
	}
	*i = idx;
	return (ret);
}

int			chr_p(const char *str, int *i, int *ret)
{
	while (str[*i] != '%' && str[*i])
	{
		write(1, &str[(*i)++], 1);
		(*ret)++;
	}
	return (*ret);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		ret;
	int		temp;

	i = 0;
	ret = 0;
	va_start(ap, str);
	while (str[i])
	{
		ret = chr_p(str, &i, &ret);
		if (str[i] == 0)
			return (ret);
		if (str[i] == '%')
		{
			temp = check_cond(str, ap, &i);
			if (temp == -1)
				return (-1);
			ret += temp;
		}
		i++;
	}
	va_end(ap);
	return (ret);
}
