/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:50:52 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/23 12:19:00 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_all(const char *format, int i, va_list ap, t_info *info)
{
	int		ret;

	ret = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			write(1, &format[i++], 1);
			ret++;
		}
		if (format[i] == '%' && format[i] != '\0')
		{
			set_info(info);
			i = info_check(format, info, ap, ++i);
			if (info->minus == 0 && (info->width >= 2147483647
			|| info->precision >= 2147483647))
				return (-1);
			else if (info->minus != 0 && (info->width >= 2147483646
			|| info->precision >= 2147483646))
				return (-1);
			ret += print_format(format, i++, ap, info);
		}
	}
	return (ret);
}

int			print_format(const char *format, int i, va_list ap, t_info *info)
{
	int		ret;

	ret = 0;
	if (format[i] == 'd' || format[i] == 'i')
		ret += print_num(ap, info);
	else if (format[i] == 's' || format[i] == 'c' || format[i] == '%')
		ret += print_scper(ap, info, format[i]);
	else if (format[i] == 'u')
		ret += print_u(ap, info);
	else if (format[i] == 'x' || format[i] == 'X')
		ret += print_x(ap, info, format[i]);
	else if (format[i] == 'p')
		ret += print_p(ap, info);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	int			i;
	t_info		*info;

	ret = 0;
	i = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (-1);
	va_start(ap, format);
	ret = print_all(format, i, ap, info);
	free(info);
	return (ret);
}
