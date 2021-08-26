/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 09:10:01 by daekim            #+#    #+#             */
/*   Updated: 2021/05/23 13:49:30 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

ssize_t		ft_atoi(const char *str)
{
	int				i;
	ssize_t			result;
	long long int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	if (!('0' <= str[i] && str[i] <= '9'))
		return (2147483649);
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		result = (result * 10) + (str[i++] - '0');
		if ((sign < 0 && result > 2147483648)
				|| (sign > 0 && result > 2147483647))
			return (2147483649);
	}
	if (str[i] != 0 && !('0' <= str[i] && str[i] <= '9'))
		return (2147483649);
	return (sign * result);
}
