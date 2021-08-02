/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:51:27 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/21 20:33:16 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_unsigned_ten(unsigned int n, t_info *info, int *count)
{
	int		prec;
	char	*str;

	prec = 0;
	*count = itoa_unsigned_count(n);
	if (info->precision != -1)
		info->zero = 0;
	if (n < 0 && info->zero == 1 && info->precision == -1
	&& *count < info->width)
		prec = info->width - *count;
	if (n < 0 && info->minus != 2 && info->precision >= *count)
		prec = info->precision - *count + 1;
	else if (info->minus != 2 && info->precision > *count)
		prec = info->precision - *count;
	*count += prec;
	if (!(str = (char *)ft_calloc((*count + 1), sizeof(char))))
		return (NULL);
	fill_unsigned_s(str, n, *count, prec);
	return (str);
}

int			itoa_unsigned_count(unsigned int n)
{
	int			count;
	long long	i;

	i = (long long)n;
	count = 0;
	if (i == 0)
		count = 1;
	if (i < 0)
	{
		count++;
		i *= -1;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

void		fill_unsigned_s(char *str, unsigned int n, int count, int prec)
{
	int			flag;
	long long	i;

	i = (long long)n;
	flag = 1;
	count -= 1;
	if (i == 0)
		str[count--] = '0';
	if (i < 0)
	{
		flag = -1;
		i *= -1;
	}
	while (i > 0)
	{
		str[count--] = i % 10 + '0';
		i /= 10;
	}
	while (prec--)
		str[count--] = '0';
	if (flag == -1)
		str[count] = '-';
}
