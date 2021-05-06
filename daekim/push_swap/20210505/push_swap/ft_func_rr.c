/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:01:00 by junghan           #+#    #+#             */
/*   Updated: 2021/04/26 21:37:28 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	func_rra(t_link *st_a)//1개일 때는??
{
	if (st_a->head == NULL)
		return ;
	st_a->head->pre = st_a->tail;
	st_a->tail->next = st_a->head;
	st_a->head = st_a->tail;
	st_a->tail = st_a->tail->pre;
	st_a->head->pre = NULL;
	st_a->tail->next = NULL;
	printf("rra\n");
}

void	func_rrb(t_link *st_b)
{
	if (st_b->head == NULL)
		return ;
	st_b->head->pre = st_b->tail;
	st_b->tail->next = st_b->head;
	st_b->head = st_b->tail;
	st_b->tail = st_b->tail->pre;
	st_b->head->pre = NULL;
	st_b->tail->next = NULL;
	printf("rrb\n");
}

void	func_rrr(t_link *st_a, t_link *st_b)
{
	func_rra(st_a);
	func_rrb(st_b);
	printf("rrr\n");
}
