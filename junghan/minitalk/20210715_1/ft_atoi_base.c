/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:44:04 by junghan           #+#    #+#             */
/*   Updated: 2021/07/15 12:15:12 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli.h"

int		is_valid(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	pre_char(int *i, int *sign, char *str)
{
	while (str[*i] && (str[*i] == 32 || \
			(str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
	while (str[*i] && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			(*sign) *= -1;
		(*i)++;
	}
}

int		is_inbase(char *base, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (base[i])
	{
		if (base[i] == c)
			cnt++;
		i++;
	}
	if (cnt == 0)
		return (0);
	return (1);
}

static int		ft_atoi2(char *str, char *base, int *sign, int len)
{
	int i;
	int j;
	int sum;

	sum = 0;
	*sign = 1;
	i = 0;
	pre_char(&i, sign, str);
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (!(is_inbase(base, str[i])))
				return (sum);
			if (base[j] == str[i])
				sum = sum * len + j;
			j++;
		}
		i++;
	}
	return (sum);
}

int		ft_atoi_base(char *str, char *base)
{
	int result;
	int len;
	int sign;

	if (!(is_valid(base)))
		return (0);
	len = 0;
	while (base[len])
		len++;
	result = ft_atoi2(str, base, &sign, len);
	return (result * sign);
}
