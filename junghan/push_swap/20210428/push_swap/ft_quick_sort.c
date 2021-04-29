/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:29:27 by junghan           #+#    #+#             */
/*   Updated: 2021/04/28 21:13:15 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    quick_sort(t_link *st1, t_link *st2, t_info *info)
{
	int pivot; //기준이 되는 값
	int i; //left부터 인덱스를 세어줄 변수 (start)
	int j; //right부터 인덱스를 세어줄 변수 (end)
//	int tmp; //swap을 위한 변수
	t_circle *tmp;
	t_circle *tmp_b;

//	printf("head add %p tail add%p\n", st1->head, st1->tail);
//	printf("head add v %d tail add v %d\n", st1->head->value, st1->tail->value);
	if (info->flag == 0 && st2->head == NULL)
		return ;
//		printf("head add v %d tail add v %d\n", st2->head->value, st2->tail->value);
	if (st1->head->value == st1->tail->value && st2->head->value == st2->tail->value)
	{
//		printf("head add v %d tail add v %d\n", st1->head->value, st1->tail->value);
		return ;
	}
	if (info->flag == 1 && !st1->head)//->value == st1->tail->value)
	{
		printf("enter 1\n");
		return ;
	}

//	if (!info->flag)
//	printf("1 h %p 2 h%p f%d", st1->head, st2->head, info->flag);
//
	tmp = st1->head;
	tmp_b = st2->head;
	if (st2->head == NULL)
		printf("st2head is null\n");
	if (st1->head && st2->head)
	{
		printf("==\n");
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
	printf("===\n");
	//	printf("fir 1 head %p 1 head v %d flag %d\n", st1->head, st1->head->value, info->flag);
	//	printf("fir 2 head %p 2 head v %d flag %d\n", st2->head, st2->head->value, info->flag);
	}
	if (info->flag == 0 && st2->head == NULL)
	{
		printf("enter 2\n");
		return ;
	}
	


	pivot = st1->tail->value;    //기준이 되는 피벗값을 start로 정함
	//    i = start + 1;    //start의 다음 인덱스부터 피벗보다 큰 값을 탐색
	//    j = end;          //end의 이전 인덱스부터 피벗보다 작은 값을탐색

	//	printf("default i %d j %d \n", i, j);
//	while (st1->head == st1->tail) //엇갈릴 때까지 반복
//	{
		printf("pv %d flag %d\n", pivot, info->flag);
		while (st1->head->value > pivot) //만약 현재보다 큰값
		{
			if (info->flag == 1)
				func_ra(st1);
			else
				func_rb(st1);
		}
		while (st1->head->value < pivot) //만약 작은값이 없다면
		{
			printf("sec %d\n", info->flag);
			if (info->flag == 1)
				func_pb(st1, st2, info);             //pivot의 위치에서 멈춰야함
			else
				func_pa(st2, st1, info);
		}
//	}
//	printf("changed i %d j %d \n", i, j);
		/* 재귀함수로 탐색해줌 */
//	printf("tail value%d address%p\n", st1->tail->value, st1->tail);
		info->flag = 1;
		if (!(st1->head->value == st1->tail->value))
		quick_sort(st1, st2, info); // 피벗기준 왼쪽탐색
		info->flag = 0;
		quick_sort(st2, st1, info); //피벗기준 오른쪽탐색
}
