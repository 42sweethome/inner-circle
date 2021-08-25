/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_easy2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:37:49 by junghan           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/18 16:19:22 by junghan          ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/18 17:07:37 by daekim           ###   ########.fr       */
=======
/*   Updated: 2021/05/18 13:31:17 by junghan          ###   ########.fr       */
>>>>>>> c3b98883abf6791ced4a7d200e82c9e092bb4ce5
>>>>>>> e5f217697ff81150eaeb6143e6672b9350bf794e
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

<<<<<<< HEAD
=======
void			under_5(t_link *st_a, t_link *st_b, t_info *info, int *ret)
{
	int	a;
	int	b;
	int c;
	int d;
	int e;

>>>>>>> c3b98883abf6791ced4a7d200e82c9e092bb4ce5
	a = st_a->head->value;
	b = st_a->head->next->value;
	c = st_a->head->next->next->value;
	d = st_a->head->next->next->next->value;
	e = st_a->head->next->next->next->next->value;
<<<<<<< HEAD
	if ((a > b && a > c && a > d && a > e) ||
			(a < b && a < c && a < d && a < e))
=======

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
>>>>>>> c3b98883abf6791ced4a7d200e82c9e092bb4ce5
	{
		func_pb(st_a, st_b, info);
		under_4(st_a, st_b, info, ret);
		func_pa(st_a, st_b, info);
		if (a > b)
			func_ra(st_a, info);
		*ret = 1;
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
