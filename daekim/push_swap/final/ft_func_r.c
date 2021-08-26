/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:36:57 by daekim            #+#    #+#             */
/*   Updated: 2021/05/23 12:36:58 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	func_ra(t_link *st_a, t_info *info)
{
	if (st_a->head == NULL || st_a->head->next == NULL)
		return (0);
	st_a->tail->next = st_a->head;
	st_a->head->pre = st_a->tail;
	st_a->tail = st_a->head;
	st_a->head = st_a->head->next;
	if (st_a->head != NULL)
		st_a->head->pre = NULL;
	st_a->tail->next = NULL;
	if (!info->both && !info->check)
		write(1, "ra\n", 3);
	return (1);
}

int	func_rb(t_link *st_b, t_info *info)
{
	if (st_b->head == NULL || st_b->head->next == NULL)
		return (0);
	st_b->tail->next = st_b->head;
	st_b->head->pre = st_b->tail;
	st_b->tail = st_b->head;
	st_b->head = st_b->head->next;
	if (st_b->head != NULL)
		st_b->head->pre = NULL;
	st_b->tail->next = NULL;
	if (!info->both && !info->check)
		write(1, "rb\n", 3);
	return (1);
}

int	func_rr(t_link *st_a, t_link *st_b, t_info *info)
{
	info->both = 1;
	func_ra(st_a, info);
	func_rb(st_b, info);
	info->both = 0;
	if (!info->check)
		write(1, "rr\n", 3);
	return (1);
}
