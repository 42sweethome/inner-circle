/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:01:00 by junghan           #+#    #+#             */
/*   Updated: 2021/05/10 17:55:26 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	func_ra(t_link *st_a, t_info *info)//1개일 때는??
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
	if (!info->both && !info->check)
		printf("ra\n");
}

void	func_rb(t_link *st_b, t_info *info)//1개일 때는??
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
	if (!info->both && !info->check)
		printf("rb\n");
}

void	func_rr(t_link *st_a, t_link *st_b, t_info *info)//1개일 때는??
{
	info->both = 1;
	func_ra(st_a, info);
	func_rb(st_b, info);
	info->both = 0;
	if (!info->check)
		printf("rr\n");
}
