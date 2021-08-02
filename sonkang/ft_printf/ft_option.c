/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:46:48 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/21 20:32:48 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->precision = -1;
	info->width = 0;
}

int			head_check(const char *format, t_info *info, va_list ap, int i)
{
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			info->minus = 1;
		if (format[i] == '0')
			info->zero = 1;
		i++;
	}
	if (ft_isdigit(format[i]) == 1 || format[i] == '*')
	{
		while (ft_isdigit(format[i]) == 1)
			info->width = info->width * 10 + format[i++] - '0';
		if (format[i] == '*')
		{
			info->width = (int)va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
			i++;
		}
	}
	return (i);
}

int			info_check(const char *format, t_info *info, va_list ap, int i)
{
	i = head_check(format, info, ap, i);
	if (format[i] == '.')
	{
		info->precision = 0;
		i++;
		if (format[i] == '-')
		{
			info->minus = 2;
			i++;
		}
		while (ft_isdigit(format[i]) == 1)
			info->precision = info->precision * 10 + format[i++] - '0';
		if (format[i] == '*')
		{
			info->precision = (int)va_arg(ap, int);
			i++;
			if (info->precision < 0)
				info->precision = -1;
		}
	}
	if (info->zero == 1 && info->minus == 1)
		info->zero = 0;
	return (i);
}
