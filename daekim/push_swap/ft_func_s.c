/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:01:00 by junghan           #+#    #+#             */
/*   Updated: 2021/04/26 21:36:56 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	func_sa(t_link *st_a, t_info info)
{
	t_circle	*tmp;
	t_circle	*next_tmp;
	t_circle	*pre_tmp;
	t_circle	**head;

	head = &st_a->head;
	if (info.len_a < 2)
		return ;
	/*이 작업은 헤드를 변경하는 작업*/
	tmp = (*head);//1
	next_tmp = (*head)->next->next;//3
	/*swap & next value og*/
	(*head) = (*head)->next;//1 = 2
	(*head)->next = tmp;// 2 = 1
	tmp->next = next_tmp; // 1 = 3
	/*pre value og*/
	(*head)->pre = NULL;
	(*head)->next->pre = (*head);
	next_tmp->pre = (*head)->next;
	if (info.len_a == 2)
		st_a->tail = (*head)->next;
	printf("sa\n");
}

void	func_sb(t_link *st_b, t_info info)
{
	t_circle	*tmp;
	t_circle	*next_tmp;
	t_circle	*pre_tmp;
	t_circle	**head;

	head = &st_b->head;
	if (info.len_b < 2)
		return ;
	/*이 작업은 헤드를 변경하는 작업*/
	tmp = (*head);//1
	next_tmp = (*head)->next->next;//3
	/*swap & next value og*/
	(*head) = (*head)->next;//1 = 2
	(*head)->next = tmp;// 2 = 1
	tmp->next = next_tmp; // 1 = 3
	/*pre value og*/
	(*head)->pre = NULL;
	(*head)->next->pre = (*head);
	next_tmp->pre = (*head)->next;
	if (info.len_b == 2)
		st_b->tail = (*head)->next;
	printf("sb\n");
}


void	func_ss(t_link *st_a, t_link *st_b, t_info info)
{
	func_sa(st_a, info);
	func_sb(st_b, info);
	printf("ss\n");
}
