/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:25:51 by junghan           #+#    #+#             */
/*   Updated: 2021/05/18 21:00:30 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_info		div_b(t_link *st_a, t_link *st_b, int pivot[2], int range)
{
	int		tmp_len;
	t_info	info;

	init_info(&info);
	tmp_len = range;
	while (tmp_len-- > 0)
	{
		if (st_b->head->value > pivot[SMALL])
		{
			func_pa(st_a, st_b, &info);
			if (st_a->head->value <= pivot[LARGE])
			{
				func_ra(st_a, &info);
				info.ra++;
			}
			else
				info.pa++;
		}
		else
		{
			func_rb(st_b, &info);
			info.rb++;
		}
	}
	return (info);
}

void		rerot_b(t_link *st_b, t_info info)
{
	int		i;

	i = -1;
	while (++i < info.rb)
		func_rrb(st_b, &info);
}

int			pre_sort_b(t_link *st_a, t_link *st_b, int range, t_info *info)
{
	int ret;

	ret = 0;
	init_info(info);
	if (range < 2)
	{
		if (range == 1)
			func_pa(st_a, st_b, info);
		return (1);
	}
	ret = exit_b(st_a, st_b, range, info);
	if (ret == 1)
		return (1);
	return (0);
}

int			sort_b(t_link *st_a, t_link *st_b, int range)
{
	int		*num;
	int		ret;
	int		pivot[2];
	t_info	info;

	ret = pre_sort_b(st_a, st_b, range, &info);
	if (ret)
		return (1);
	ret = input_arr(st_b, &num);
	if (ret == 0)
		return (0);
	quick_sort(num, 0, range - 1);
	first_pivot(num, pivot, range);
	info = div_b(st_a, st_b, pivot, range);
	sort_a(st_a, st_b, info.pa);
	rerot_a(st_a, st_b, info);
	sort_a(st_a, st_b, info.ra);
	sort_b(st_a, st_b, info.rb);
	return (1);
}
