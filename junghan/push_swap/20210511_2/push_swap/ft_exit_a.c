/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:37:49 by junghan           #+#    #+#             */
/*   Updated: 2021/05/11 17:43:19 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		under_2(t_link *st_a, t_info *info)
{
	if (st_a->head->value > st_a->head->next->value)
		func_sa(st_a, *info);
}

static void		under_3(t_link *st_a, t_info *info)
{
	int		a;
	int		b;
	int		c;

	a = st_a->head->value;
	b = st_a->head->next->value;
	c = st_a->head->next->next->value;
	if (a > b && a > c)
		func_sa(st_a, *info);
	if (!(c > a && c > b))
	{
		func_ra(st_a, info);
		func_sa(st_a, *info);
		func_rra(st_a, info);
	}
	if ((a > c && a < b) || (a < c && a > b) || (a > b && b > c))
		func_sa(st_a, *info);
}

int				exit_a(t_link *st_a, int range, t_info *info)
{
	if (range == 2)
	{
		info->len_a = 2;
		under_2(st_a, info);
		return (1);
	}
	else if (range == 3)
	{
		info->len_a = 3;
		under_3(st_a, info);
		return (1);
	}
	return (0);
}
