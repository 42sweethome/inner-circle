/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:38:13 by daekim            #+#    #+#             */
/*   Updated: 2021/05/23 12:38:14 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_info		div_a(t_link *st_a, t_link *st_b, int pivot[2], int range)
{
	t_info	info;

	init_info(&info);
	if (range <= 3)
		return (info);
	while (range--)
	{
		if (st_a->head->value < pivot[LARGE])
		{
			func_pb(st_a, st_b, &info);
			if (st_b->head->value >= pivot[SMALL])
			{
				func_rb(st_b, &info);
				info.rb++;
			}
			else
				info.pb++;
		}
		else
		{
			func_ra(st_a, &info);
			info.ra++;
		}
	}
	return (info);
}

void		rerot_a(t_link *st_a, t_link *st_b, t_info info)
{
	int		i;

	i = -1;
	while (++i < info.ra && i < info.rb)
		func_rrr(st_a, st_b, &info);
	while (i < info.ra)
	{
		func_rra(st_a, &info);
		i++;
	}
	while (i < info.rb)
	{
		func_rrb(st_b, &info);
		i++;
	}
}

int			sort_a(t_link *st_a, t_link *st_b, int range)
{
	int		*num;
	int		ret;
	int		pivot[2];
	t_info	info;

	if (range < 2)
		return (1);
	init_info(&info);
	ret = exit_a(st_a, range, &info);
	if (ret == 1)
		return (1);
	ret = input_arr(st_a, &num);
	if (ret == 0)
		return (0);
	quick_sort(num, 0, range - 1);
	first_pivot(num, pivot, range);
	info = div_a(st_a, st_b, pivot, range);
	rerot_a(st_a, st_b, info);
	sort_a(st_a, st_b, info.ra);
	sort_b(st_a, st_b, info.rb);
	sort_b(st_a, st_b, info.pb);
	return (1);
}
