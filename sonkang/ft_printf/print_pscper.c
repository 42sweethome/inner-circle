/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pscper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:50:52 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/21 20:39:05 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_scper_head(int *len, t_info *info, char type)
{
	int		ret;

	ret = 0;
	if (info->minus == 0 && info->width > *len - 1)
	{
		if (info->precision == 0 && type != 'c' && type != '%')
			*len = 0;
		while (--info->width > *len - 1)
		{
			if (info->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int			print_scper_back(int len, t_info *info, char type)
{
	int		ret;

	ret = 0;
	if (info->minus == 2 && info->precision > 0)
	{
		if (type == 's')
			info->precision++;
		while (--info->precision)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	if (info->minus == 1 && info->width > len - 1)
	{
		if (info->precision == 0 && type != 'c' && type != '%')
			len = 0;
		while (--info->width > len - 1)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int			print_scper(va_list ap, t_info *info, char type)
{
	int		len;
	char	*s;
	int		ret;
	int		flag;

	flag = 0;
	ret = 0;
	len = 1;
	if (type == 's')
		len = ft_count(&s, ap, info, &flag);
	ret += print_scper_head(&len, info, type);
	if (type == 's' && info->minus != 2 && info->precision != 0)
		ret += print_str(s, &len, info);
	else if (type == 'c')
		ret += print_char(ap);
	else if (type == '%')
		ret += ft_write(1, "%");
	ret += print_scper_back(len, info, type);
	if (flag == -1)
		free(s);
	return (ret);
}

int			print_p(va_list ap, t_info *info)
{
	char	*str;
	int		len;
	int		ret;

	len = 0;
	str = ft_p((size_t)va_arg(ap, size_t), info, &len);
	if (str[3] == '\0' && info->precision == 0)
		len = 2;
	ret = 0;
	if (info->minus == 0)
	{
		if (info->zero == 1 && str[0] != '-')
			ret += ft_write(info->width - len, "0");
		else
			ret += ft_write(info->width - len, " ");
	}
	ret += write(1, str, len);
	if (info->minus == 1)
		ret += ft_write(info->width - len, " ");
	if (info->minus == 2)
		ret += ft_write(info->precision - len, " ");
	free(str);
	return (ret);
}
