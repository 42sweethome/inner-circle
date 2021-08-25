/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_easy2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:37:49 by junghan           #+#    #+#             */
/*   Updated: 2021/05/18 16:23:28 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		sec_sort(t_link *st_a, t_link *st_b, t_info *info, int *ret)
{
	func_pb(st_a, st_b, info);
	func_ra(st_a, info);
	func_ra(st_a, info);
	func_sa(st_a, *info);
	func_rra(st_a, info);
	func_pa(st_a, st_b, info);
	func_ra(st_a, info);
	*ret = 1;
}

static void		fir_sort(t_link *st_a, t_link *st_b, t_info *info, int *ret)
{
	func_pb(st_a, st_b, info);
	func_sa(st_a, *info);
	func_ra(st_a, info);
	func_sa(st_a, *info);
	func_pa(st_a, st_b, info);
	func_ra(st_a, info);
	*ret = 1;
}

void			under_5(t_link *st_a, t_link *st_b, t_info *info, int *ret)
{
	int	a;
	int	b;
	int c;
	int d;
	int e;

	a = st_a->head->value;
	b = st_a->head->next->value;
	c = st_a->head->next->next->value;
	d = st_a->head->next->next->next->value;
	e = st_a->head->next->next->next->next->value;

	if (st_a->head->next->next->next->value < st_a->head->next->value
			&& st_a->head->next->value <
			st_a->head->next->next->next->next->value
			&& st_a->head->next->next->next->next->value <
			st_a->head->next->next->value
			&& st_a->head->next->next->value < st_a->head->value)
	{
		fir_sort(st_a, st_b, info, ret);
	}
	else if (st_a->head->next->next->value <
			st_a->head->next->next->next->next->value
			&& st_a->head->next->next->next->next->value <
			st_a->head->next->next->next->value
			&& st_a->head->next->next->next->value < st_a->head->next->value
			&& st_a->head->next->value < st_a->head->value)
	{
		sec_sort(st_a, st_b, info, ret);
	}
	else if (a > b && a > c && a > d && a > e)
	{
		func_pb(st_a, st_b, info);
		*ret = check_sort(st_a, st_b, info);
		if (*ret == 0)
			*ret = sort_a(st_a, st_b, 4);
		//sort_a(st_a, st_b, 4);
		func_pa(st_a, st_b, info);
		func_ra(st_a, info);
		*ret = 1;
	}
}
