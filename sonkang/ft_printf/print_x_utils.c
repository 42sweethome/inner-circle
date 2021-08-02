/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:53:44 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/19 20:04:18 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_x(unsigned int hex, t_info *info, int *len, char type)
{
	char		*str;
	int			prec;
	int			i;

	prec = 0;
	*len = count_hex(hex);
	if (info->precision != -1)
		info->zero = 0;
	if (info->minus != 2 && info->precision > *len)
		prec = info->precision - *len;
	*len += prec;
	if (!(str = (char *)ft_calloc((*len + 1), sizeof(char))))
		return (NULL);
	fill_x(str, hex, *len);
	i = -1;
	if (type == 'X')
		while (str[++i])
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] -= 32;
	return (str);
}

int				count_hex(unsigned int hex)
{
	int			len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex)
	{
		len++;
		hex /= 16;
	}
	return (len);
}

void			fill_x(char *str, unsigned int hex, int len)
{
	char	base[16];
	int		i;

	i = -1;
	while (++i < 16)
	{
		if (i < 10)
			base[i] = i + '0';
		else if (i < 16)
			base[i] = i + 'a' - 10;
	}
	len--;
	while (hex)
	{
		str[len--] = base[hex % 16];
		hex /= 16;
	}
	while (len >= 0)
		str[len--] = '0';
}
