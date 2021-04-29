/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:01:33 by junghan           #+#    #+#             */
/*   Updated: 2021/04/29 18:59:20 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_list(t_link *st)
{
	int	check1;
	int	check2;
	t_circle *tmp;


	tmp = st->head;
	if (!tmp)
		return (-1);
	check1 = tmp->value;
	check2 = tmp->next->value;
	while (tmp->next)
	{
		if (check1 >= check2)
			return (0);
		else
		{
			tmp = tmp->next;
			if (!tmp->next)
				break;
			check1 = tmp->value;
			check2 = tmp->next->value;
		}
	}
	return (1);
}

int	quick_b(t_link *st_a, t_link *st_b, t_info *info)
{
	int	pivot;
	int tmp_len;
	int	tail;
	int	check;
	int	i;
	t_circle *tmp;
	t_circle *tmp_b;

	i = 0;
	if (info->len_b < 2)
		return (0);
	check = check_list(st_b);
	if (info->len_b < 3 && check)
	{
		return (0);
	}
	pivot = st_b->tail->value;
	tmp_len = info->len_b;
	tail = st_b->tail->value;
	printf("head%d tail%d\n",st_b->head->value, tail);
	while (st_b->head->value != tail && !check)
	{
		if (pivot > st_b->head->value)//큰수 넘기기
		{
			func_rb(st_b);
			i++;
		}
		else
		{
			func_pa(st_a, st_b, info);
		}
	}
	while (--i > 0)
	{
		func_rrb(st_b);
	}
//출력
	tmp = st_a->head;
	tmp_b = st_b->head;
	while (tmp)
	{
		printf("a = %d\n", tmp->value);
		tmp = tmp->next;
	}
	while (tmp_b)
	{
		printf("b = %d\n", tmp_b->value);
		tmp_b = tmp_b->next;
	}
//출력

//	if (info->len_b < 3 && check != 0)
//		func_sb(st_b, *info)[A;
	info->pre_b_pivot = st_b->head;
	printf("%p %p\n", info->pre_a_pivot, st_a->head);
	if (info->pre_a_pivot != st_a->head)
		quick_a(st_a, st_b, info);
	quick_b(st_a, st_b, info);
	return (0);
}		

int	quick_a(t_link *st_a, t_link *st_b, t_info *info)
{
	int	pivot;
	int tmp_len;
	int	tail;
	int	check;
	t_circle **tmp_pv;
	t_circle *tmp;
	t_circle *tmp_b;

	tmp_pv = &info->pre_a_pivot;
	pivot = st_a->tail->value;
	tmp_len = info->len_a;
	tail = st_a->tail->value;

	if (info->len_a < 2)
		return (0);
	check = check_list(st_a);
	if (check)
		*tmp_pv = st_a->head;
	if (info->len_a < 3 && check)
		return (0);
	if (info->pre_a_pivot != NULL)
		printf("head%d tail%d prepivot%d\n",st_a->head->value, tail, info->pre_a_pivot->value);
	while (st_a->head->value != tail && !check && info->pre_a_pivot != st_a->head)
	{
		if (pivot < st_a->head->value)//큰수 넘기기
		{
			func_ra(st_a);
		}
		else
		{
			func_pb(st_a, st_b, info);
		}
		tmp_len--;
		if (tmp_len > 1 && st_a->head->value == tail)
		{
			return (-1);// 중복값 오류처리
		}
	}
	if (info->len_a < 3 && check != 0)
		func_sa(st_a, *info);

//출력
	tmp = st_a->head;
	tmp_b = st_b->head;
	while (tmp)
	{
		printf("a = %d\n", tmp->value);
		tmp = tmp->next;
	}
	while (tmp_b)
	{
		printf("b = %d\n", tmp_b->value);
		tmp_b = tmp_b->next;
	}
//출력
	printf("enter A\n");
	if (!check && info->pre_a_pivot != st_a->head)
		quick_a(st_a, st_b, info);
	printf("enter B\n");
	quick_b(st_a, st_b, info);
	return (0);
}		
