/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:01:00 by junghan           #+#    #+#             */
/*   Updated: 2021/05/10 17:55:13 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	func_sa(t_link *st_a, t_info info)
{
	t_circle	*tmp;
	t_circle	*next_tmp;
	t_circle	*head;

	tmp = st_a->head;
	if (st_a->head == NULL || st_a->head->next == NULL)
		return ;
	next_tmp = tmp->next->next;
	st_a->head = st_a->head->next;
	st_a->head->pre = NULL;
	st_a->head->next = tmp;
	st_a->head->next->pre = st_a->head;
	st_a->head->next->next = next_tmp;
	if (next_tmp != NULL)
		st_a->head->next->next->pre = st_a->head->next;
	if (next_tmp == NULL)
		st_a->tail = tmp;
	if (!info.both && !info.check)
		printf("sa\n");
}

void	func_sb(t_link *st_b, t_info info)
{
	t_circle	*tmp;
	t_circle	*next_tmp;
	t_circle	*head;

	tmp = st_b->head;
	if (st_b->head == NULL || st_b->head->next == NULL)
		return ;
	next_tmp = tmp->next->next;
	st_b->head = st_b->head->next;
	st_b->head->pre = NULL;
	st_b->head->next = tmp;
	st_b->head->next->pre = st_b->head;
	st_b->head->next->next = next_tmp;
	if (next_tmp != NULL)
		st_b->head->next->next->pre = st_b->head->next;
	if (next_tmp == NULL)
		st_b->tail = tmp;
	if (!info.both && !info.check)
		printf("sb\n");
}


void	func_ss(t_link *st_a, t_link *st_b, t_info *info)
{
	info->both = 1;
	func_sa(st_a, *info);
	func_sb(st_b, *info);
	info->both = 0;
	if (!info->check)
		printf("ss\n");
}
