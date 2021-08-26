/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seou.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:15:51 by daekim            #+#    #+#             */
/*   Updated: 2021/02/02 17:45:14 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_hex(va_list ap, char c, t_cond *con)
{
	int		ret;
	size_t	num;
	char	*output;
	int		i;
	int		len;

	ret = 0;
	num = va_arg(ap, unsigned int);
	if (!(output = ten_hex(num, con)))
		return (-1);
	i = 0;
	while (output[i])
	{
		if (c == 'X')
			output[i] = ft_toupper(output[i]);
		i++;
	}
	len = ft_strlen(output + 2);
	ret = print_num(output + 2, con, len, &ret);
	free(output);
	output = 0;
	return (ret);
}

int			put_uni(va_list ap, t_cond *con)
{
	int		ret;
	ssize_t	num;
	char	*output;
	int		len;

	ret = 0;
	num = va_arg(ap, unsigned int);
	if (!(output = ten_ten(num, con)))
		return (-1);
	len = ft_strlen(output);
	ret = print_num(output, con, len, &ret);
	free(output);
	output = 0;
	return (ret);
}

int			put_dig(va_list ap, t_cond *con)
{
	int		ret;
	ssize_t num;
	char	*output;
	int		len;

	ret = 0;
	num = va_arg(ap, int);
	if (!(output = ten_ten(num, con)))
		return (-1);
	len = ft_strlen(output);
	ret = print_num(output, con, len, &ret);
	free(output);
	output = 0;
	return (ret);
}
