/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:50:52 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/19 20:10:11 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_num(va_list ap, t_info *info)
{
	char	*str;
	int		len;
	int		ret;

	len = 0;
	str = ft_ten((int)va_arg(ap, int), info, &len);
	if (str[0] == '0' && info->precision == 0)
		len = 0;
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

int			print_u(va_list ap, t_info *info)
{
	char	*str;
	int		len;
	int		ret;

	len = 0;
	str = ft_unsigned_ten((unsigned int)va_arg(ap, unsigned int), info, &len);
	if (str[0] == '0' && info->precision == 0)
		len = 0;
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

int			print_x(va_list ap, t_info *info, char type)
{
	char	*str;
	int		len;
	int		ret;

	len = 0;
	str = ft_x((unsigned int)va_arg(ap, unsigned int), info, &len, type);
	if (str[0] == '0' && info->precision == 0)
		len = 0;
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
