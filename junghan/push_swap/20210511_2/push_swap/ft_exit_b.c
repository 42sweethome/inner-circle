/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:34:54 by junghan           #+#    #+#             */
/*   Updated: 2021/05/11 17:43:32 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		under_2(t_link *st_a, t_link *st_b, t_info *info)
{
	if (st_b->head->value < st_b->head->next->value)
		func_sb(st_b, *info);
	func_pa(st_a, st_b, info);
	func_pa(st_a, st_b, info);
}

static void		under_3(t_link *st_a, t_link *st_b, t_info *info)
{
	int		a;
	int		b;
	int		c;

	a = st_b->head->value;
	b = st_b->head->next->value;
	c = st_b->head->next->next->value;
	if (a > b && a > c)
	{
		func_pa(st_a, st_b, info);
		func_pa(st_a, st_b, info);
		func_pa(st_a, st_b, info);
		exit_a(st_a, 2, info);
	}
	else
	{
		func_pa(st_a, st_b, info);
		if (b < c)
			func_sb(st_b, *info);
		func_pa(st_a, st_b, info);
		exit_a(st_a, 2, info);
		func_pa(st_a, st_b, info);
		exit_a(st_a, 2, info);
	}
}

int				exit_b(t_link *st_a, t_link *st_b, int range, t_info *info)
{
	if (range == 2)
	{
		info->len_b = 2;
		under_2(st_a, st_b, info);
		return (1);
	}
	else if (range == 3)
	{
		info->len_b = 3;
		under_3(st_a, st_b, info);
		return (1);
	}
	return (0);
}
