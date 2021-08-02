/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:45:59 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/19 18:46:00 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				count_p(size_t p)
{
	int			len;

	len = 0;
	if (p == 0)
		return (1);
	while (p)
	{
		len++;
		p /= 16;
	}
	return (len);
}

void			fill_p(char *str, size_t p, int len)
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
	while (p)
	{
		str[len--] = base[p % 16];
		p /= 16;
	}
	while (len > 1)
		str[len--] = '0';
	str[0] = '0';
	str[1] = 'x';
}

char			*ft_p(size_t p, t_info *info, int *len)
{
	char		*str;
	int			prec;

	prec = 0;
	*len = count_p(p);
	if (info->precision != -1)
		info->zero = 0;
	if (info->minus != 2 && info->precision > *len)
		prec = info->precision - *len;
	*len = *len + prec + 2;
	if (!(str = (char *)ft_calloc((*len + 1), sizeof(char))))
		return (NULL);
	fill_p(str, p, *len);
	return (str);
}
