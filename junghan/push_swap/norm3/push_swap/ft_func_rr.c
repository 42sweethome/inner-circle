/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:01:00 by junghan           #+#    #+#             */
/*   Updated: 2021/05/16 15:47:10 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	func_rra(t_link *st_a, t_info *info)
{
	if (st_a->head == NULL || st_a->head->next == NULL)
		return (0);
	st_a->head->pre = st_a->tail;
	st_a->tail->next = st_a->head;
	st_a->head = st_a->tail;
	st_a->tail = st_a->tail->pre;
	st_a->head->pre = NULL;
	if (st_a->tail != NULL)
		st_a->tail->next = NULL;
	if (!info->both && !info->check)
		write(1, "rra\n", 4);
	return (1);
}

int	func_rrb(t_link *st_b, t_info *info)
{
	if (st_b->head == NULL || st_b->head->next == NULL)
		return (0);
	st_b->head->pre = st_b->tail;
	st_b->tail->next = st_b->head;
	st_b->head = st_b->tail;
	st_b->tail = st_b->tail->pre;
	st_b->head->pre = NULL;
	if (st_b->tail != NULL)
		st_b->tail->next = NULL;
	if (!info->both && !info->check)
		write(1, "rrb\n", 4);
	return (1);
}

int	func_rrr(t_link *st_a, t_link *st_b, t_info *info)
{
	info->both = 1;
	func_rra(st_a, info);
	func_rrb(st_b, info);
	info->both = 0;
	if (!info->check)
		write(1, "rrr\n", 4);
	return (1);
}
