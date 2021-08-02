/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:48:56 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/19 19:56:40 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

char			*ft_ten(int n, t_info *info, int *count)
{
	int		prec;
	char	*str;

	prec = 0;
	*count = itoa_count(n);
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
	fill_str(str, n, *count, prec);
	return (str);
}

int				itoa_count(int n)
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

void			fill_str(char *str, int n, int count, int prec)
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
