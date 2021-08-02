/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sc%_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:43:38 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/19 18:43:39 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_str(char *s, int *len, t_info *info)
{
	if (*len >= info->precision && info->precision != -1)
		*len = info->precision;
	write(1, s, *len);
	return (*len);
}

int			ft_count(char **s, va_list ap, t_info *info, int *flag)
{
	int		len;

	*s = (char *)va_arg(ap, char*);
	if (*s == 0)
	{
		*s = ft_strdup("(null)");
		*flag = -1;
	}
	len = ft_strlen(*s);
	if (len >= info->precision && info->precision != -1)
		len = info->precision;
	return (len);
}

int			print_char(va_list ap)
{
	char ch;

	ch = (char)va_arg(ap, int);
	write(1, &ch, sizeof(char));
	return (1);
}
