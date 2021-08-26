/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:36:51 by daekim            #+#    #+#             */
/*   Updated: 2021/05/23 12:36:52 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	func_pa(t_link *st_a, t_link *st_b, t_info *info)
{
	t_circle *tmp;

	if (st_b->head == NULL)
		return (0);
	(info->len_a)++;
	(info->len_b)--;
	tmp = st_a->head;
	st_a->head = st_b->head;
	st_a->head->pre = NULL;
	st_b->head = st_b->head->next;
	if (st_b->head != NULL)
		st_b->head->pre = NULL;
	if (!tmp)
	{
		st_a->head->next = NULL;
		st_a->tail = st_a->head;
	}
	else
	{
		st_a->head->next = tmp;
		tmp->pre = st_a->head;
	}
	if (!info->check)
		write(1, "pa\n", 3);
	return (1);
}

int	func_pb(t_link *st_a, t_link *st_b, t_info *info)
{
	t_circle *tmp;

	if (st_a->head == NULL)
		return (0);
	(info->len_a)--;
	(info->len_b)++;
	tmp = st_b->head;
	st_b->head = st_a->head;
	st_b->head->pre = NULL;
	st_a->head = st_a->head->next;
	if (st_a->head != NULL)
		st_a->head->pre = NULL;
	if (!tmp)
	{
		st_b->head->next = NULL;
		st_b->tail = st_b->head;
	}
	else
	{
		st_b->head->next = tmp;
		tmp->pre = st_b->head;
	}
	if (!info->check)
		write(1, "pb\n", 3);
	return (1);
}
