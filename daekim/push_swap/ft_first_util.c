/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:29:27 by junghan           #+#    #+#             */
/*   Updated: 2021/04/22 16:53:49 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	first_div(t_link *st_a, t_link *st_b, int pivot[3], t_info *info)
{
	int		i;
	int		tmp_len;

	i = -1;
	tmp_len = info->len_a;
	while (++i < tmp_len)
	{
		if (st_a->head->value < pivot[LARGE])
		{
			func_pb(st_a, st_b, info);
			if (st_a->head->value < pivot[SMALL])
			{
				func_rb(st_b);
				info->rb++;
			}
			else
				info->pb++;
//			if (st_b->head->value == pivot[LAST])
//				break ;
			// Last의 역할 모호;
		}
		else
		{
			func_ra(st_a);
			info->ra++;
		}
	}
}

void	first_pivot(int *num, int pivot[3], int size)
{
	pivot[SMALL] = num[size / 3];
	pivot[LARGE] = num[size * 2 / 3];
	pivot[LAST] = 0; 
	free(num);
	num = 0;
}

int		input_arr(t_link *st_a, int **num)
{
	t_circle	*tmp;
	int			size;
	int			i;

	if (st_a->head == NULL)
		return (0);
	tmp = st_a->head;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	tmp = st_a->head;
	*num = (int *)ft_calloc(size, sizeof(int));
	if (!*num)
		return (0);
	i = 0;
	while (i < size)
	{
		(*num)[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (size);
}

void    quick_sort(int *st_a, int start, int end)
{
	int pivot; //기준이 되는 값
    int i; //left부터 인덱스를 세어줄 변수 (start)
    int j; //right부터 인덱스를 세어줄 변수 (end)
    int tmp; //swap을 위한 변수

    if (start >= end) //만약 1일경우 종료 base_condition; 
        return ;       //상위목차의 merge와 같음

    pivot = start;    //기준이 되는 피벗값을 start로 정함
    i = start + 1;    //start의 다음 인덱스부터 피벗보다 큰 값을 탐색
    j = end;          //end의 이전 인덱스부터 피벗보다 작은 값을탐색
    while (i <= j) //엇갈릴 때까지 반복
    {
        while(st_a[i] <= st_a[pivot] && i < j) //만약 현재보다 큰값//오류있어서 i < j로 바꿈
            i++;
        while (st_a[j] >= st_a[pivot] && j > start) //만약 작은값이 없다면
            j--;                 //pivot의 위치에서 멈춰야함 
        if (i >= j)
        {
            tmp = st_a[j];
            st_a[j] = st_a[pivot];
            st_a[pivot] = tmp;
        }
        else
        {
            tmp = st_a[i];
            st_a[i] = st_a[j];
            st_a[j] = tmp;
        }
    }
    quick_sort(st_a, start, j - 1); // 피벗기준 왼쪽탐색
    quick_sort(st_a, j + 1, end); //피벗기준 오른쪽탐색
}

