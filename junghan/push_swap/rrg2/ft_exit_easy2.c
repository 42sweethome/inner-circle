/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_easy2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:37:49 by junghan           #+#    #+#             */
/*   Updated: 2021/05/18 17:18:17 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		under_5(t_link *st_a, t_link *st_b, t_info *info, int *ret)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;

	a = st_a->head->value;
	b = st_a->head->next->value;
	c = st_a->head->next->next->value;
	d = st_a->head->next->next->next->value;
	e = st_a->head->next->next->next->next->value;
	if ((a > b && a > c && a > d && a > e) ||
			(a < b && a < c && a < d && a < e))
	{
		func_pb(st_a, st_b, info);
		under_4(st_a, st_b, info, ret);
		func_pa(st_a, st_b, info);
		if (a > b)
			func_ra(st_a, info);
		*ret = 1;
	}
}
