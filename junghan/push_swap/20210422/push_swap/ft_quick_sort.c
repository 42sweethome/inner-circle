/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:29:27 by junghan           #+#    #+#             */
/*   Updated: 2021/04/22 16:53:49 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    quick_sort(int *st_a, int *st_b, int start, int end)
{
    int pivot; //기준이 되는 값
    int i; //left부터 인덱스를 세어줄 변수 (start)
    int j; //right부터 인덱스를 세어줄 변수 (end)
    int tmp; //swap을 위한 변수

    if (start >= end) //만약 1일경우 종료 base_condition; 
        return;       //상위목차의 merge와 같음

    pivot = start;    //기준이 되는 피벗값을 start로 정함
    i = start + 1;    //start의 다음 인덱스부터 피벗보다 큰 값을 탐색
    j = end;          //end의 이전 인덱스부터 피벗보다 작은 값을탐색

	printf("default i %d j %d \n", i, j);
    while (i <= j) //엇갈릴 때까지 반복
    {
        while(st_a[i] <= st_a[pivot]) //만약 현재보다 큰값
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
	printf("changed i %d j %d \n", i, j);
    /* 재귀함수로 탐색해줌 */
    quick_sort(st_a, st_b, start, j - 1); // 피벗기준 왼쪽탐색
    quick_sort(st_a, st_b, j + 1, end); //피벗기준 오른쪽탐색
}

