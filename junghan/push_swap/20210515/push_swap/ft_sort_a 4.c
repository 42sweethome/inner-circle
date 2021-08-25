/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:20:48 by junghan           #+#    #+#             */
/*   Updated: 2021/05/16 11:35:35 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_info		div_a(t_link *st_a, t_link *st_b, int pivot[3], int range)
{
	t_info	info;

	info.check = pre_div_a(st_a, range, &info);
	if (info.check)
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

int			last_small(t_link *st_a, int large)
{
	int			num;
	int			last;
	t_circle	*tmp;

	last = 0;
	tmp = st_a->head;
	while (tmp)
	{
		num = tmp->value;
		if (num < large)
			last = num;
		tmp = tmp->next;
	}
	return (last);
}

void		rerot_a(t_link *st_a, t_info info)
{
	int		i;

	i = -1;
	while (++i < info.ra)
		func_rra(st_a, &info);
}

int			sort_a(t_link *st_a, t_link *st_b, int range)
{
	int		*num;
	int		ret;
	int		pivot[3];
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
	pivot[LAST] = last_small(st_a, pivot[LARGE]);
	info = div_a(st_a, st_b, pivot, range);
	rerot_a(st_a, info);
	sort_a(st_a, st_b, info.ra);
	rerot_b(st_b, info);
	sort_b(st_a, st_b, info.rb);
	sort_b(st_a, st_b, info.pb);
	return (1);
}
