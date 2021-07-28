/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:01:00 by junghan           #+#    #+#             */
/*   Updated: 2021/04/26 21:37:12 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	func_ra(t_link *st_a)//1개일 때는??
{
	if (st_a->head == NULL || st_a->head->next == NULL)
		return ;
	st_a->tail->next = st_a->head;
	st_a->head->pre = st_a->tail;
	st_a->tail = st_a->head;
	st_a->head = st_a->head->next;
	if (st_a->head != NULL)
		st_a->head->pre = NULL;
	st_a->tail->next = NULL;
	printf("ra\n");
}

void	func_rb(t_link *st_b)//1개일 때는??
{
	if (st_b->head == NULL || st_b->head->next == NULL)
		return ;
	st_b->tail->next = st_b->head;
	st_b->head->pre = st_b->tail;
	st_b->tail = st_b->head;
	st_b->head = st_b->head->next;
	if (st_b->head != NULL)
		st_b->head->pre = NULL;
	st_b->tail->next = NULL;
	printf("rb\n");
}

void	func_rr(t_link *st_a, t_link *st_b)//1개일 때는??
{
	func_ra(st_a);
	func_rb(st_b);
	printf("rr\n");
}
