/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_easy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:37:49 by junghan           #+#    #+#             */
/*   Updated: 2021/05/18 13:35:07 by junghan          ###   ########.fr       */
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
	if ((b > a && b > c) && c > a)
	{
		func_rra(st_a, info);
		func_sa(st_a, *info);
	}
	else if (a > b && b > c)
	{
		func_ra(st_a, info);
		func_sa(st_a, *info);
	}
	else if ((c > a && c > b) && a > b)
		func_sa(st_a, *info);
	else if ((b > a && b > c) && a > c)
		func_rra(st_a, info);
	else if ((a > b && a > c) && c > b)
		func_ra(st_a, info);
	*ret = 1;
}

static void		under_4(t_link *st_a, t_link *st_b, t_info *info, int *ret)// ㅎㅐ결 필요. 
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = st_a->head->value;
	b = st_a->head->next->value;
	c = st_a->head->next->next->value;
	d = st_a->head->next->next->next->value;
	if (a < b && a < c && a< d)
	{
		func_pb(st_a, st_b, info);
		under_3(st_a, info, ret);
		func_pa(st_a, st_b, info);
		*ret = 1;
	}
	else if (b < a && a < c && c < d)
	{
		func_sa(st_a, *info);
		*ret = 1;
	}
	if (a > b && a > c && a > d)
	{
		func_pb(st_a, st_b, info);
		under_3(st_a, info, ret);
		func_pa(st_a, st_b, info);
		func_ra(st_a, info);
		*ret = 1;
	}
}

int				exit_easy(t_link *st_a, t_link *st_b, int range, t_info *info)
{
	int	ret;

	ret = 0;
	if (range == 1)
		ret = 1;
	else if (range == 2)
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
		under_4(st_a, st_b, info, &ret);
	}
	else if (range == 5)
		under_5(st_a, st_b, info, &ret);
	return (ret);
}
