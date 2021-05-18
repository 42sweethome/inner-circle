/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:37:49 by junghan           #+#    #+#             */
/*   Updated: 2021/05/18 15:56:21 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		under_2(t_link *st_a, t_info *info, int *ret)
{
	if (st_a->head->value > st_a->head->next->value)
		func_sa(st_a, *info);
	*ret = 1;
}

static void		under_3(t_link *st_a, t_info *info, int *ret)
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
	*ret = 1;
}

static void		under_4a(t_link *st_a, t_info *info, int *ret)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = st_a->head->value;
	b = st_a->head->next->value;
	c = st_a->head->next->next->value;
	d = st_a->head->next->next->next->value;
	if (a < b && a < c && a < d)
	{
		func_ra(st_a, info);
		under_3(st_a, info, ret);
		func_rra(st_a, info);
		*ret = 1;
	}
	else if (b < a && a < c && c < d)
	{
		func_sa(st_a, *info);
		*ret = 1;
	}
}

int				exit_a(t_link *st_a, int range, t_info *info)
{
	int ret;

	ret = 0;
	if (range == 2)
	{
		info->len_a = 2;
		under_2(st_a, info, &ret);
	}
	else if (range == 3)
	{
		info->len_a = 3;
		under_3(st_a, info, &ret);
	}
	else if (range == 4)
	{
		info->len_a = 4;
		under_4a(st_a, info, &ret);
	}
	return (ret);
}
