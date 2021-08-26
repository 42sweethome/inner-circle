/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:13:49 by daekim            #+#    #+#             */
/*   Updated: 2021/02/02 14:51:56 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_per(char c, t_cond *con)
{
	int		ret;

	ret = 0;
	ret = print_c(c, con, &ret);
	return (ret);
}

int			put_chr(va_list ap, t_cond *con)
{
	int		ret;
	int		output;

	ret = 0;
	output = va_arg(ap, int);
	ret = print_c(output, con, &ret);
	return (ret);
}

int			put_str(va_list ap, t_cond *con)
{
	int		ret;
	char	*output;
	int		len;

	ret = 0;
	output = va_arg(ap, char *);
	if (!output)
		if (!(output = ft_strdup("(null)")))
			return (-1);
	len = ft_strlen(output);
	if (len > con->pre && con->minus_pre == 0 && con->dot == 1)
		len = con->pre;
	ret = print_str(output, con, len, &ret);
	if (!output)
	{
		free(output);
		output = 0;
	}
	return (ret);
}

int			put_poi(va_list ap, t_cond *con)
{
	int		ret;
	char	*output;
	size_t	num;
	int		len;

	ret = 0;
	num = va_arg(ap, size_t);
	con->poi = 1;
	if (!(output = ten_hex(num, con)))
		return (-1);
	len = ft_strlen(output);
	ret = print_poi(output, con, len, &ret);
	free(output);
	output = 0;
	return (ret);
}
