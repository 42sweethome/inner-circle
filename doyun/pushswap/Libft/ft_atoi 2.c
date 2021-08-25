/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:59:08 by doyun             #+#    #+#             */
/*   Updated: 2021/06/17 11:28:57 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str, int *flag)
{
	int				idx;
	int				miner;
	long long int	num;

	idx = 0;
	miner = 1;
	num = 0;
	if (str[idx] == 43 || str[idx] == 45)
	{
		if (str[idx] == 45)
			miner *= -1;
		idx++;
	}
	if (str[idx] == '\0')
		return (*flag = 0);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + (str[idx++] - 48);
		if (num * miner > 2147483647 || num * miner < -2147483648)
			return (*flag = 0);
	}
	if (str[idx] != '\0')
		return (*flag = 0);
	return (num * miner);
}
