/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:38:04 by daekim            #+#    #+#             */
/*   Updated: 2021/05/23 12:38:04 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	conquer(int *st_a, int i, int j, int pivot)
{
	int	tmp;

	if (i >= j)
	{
		tmp = st_a[j];
		st_a[j] = st_a[pivot];
		st_a[pivot] = tmp;
		i++;
	}
	else
	{
		tmp = st_a[i];
		st_a[i] = st_a[j];
		st_a[j] = tmp;
	}
}

void	quick_sort(int *st_a, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = start;
	i = start + 1;
	j = end;
	while (i <= j)
	{
		while (st_a[i] <= st_a[pivot] && i < end)
			i++;
		while (st_a[j] >= st_a[pivot] && j > start)
			j--;
		conquer(st_a, i, j, pivot);
	}
	quick_sort(st_a, start, j - 1);
	quick_sort(st_a, j + 1, end);
}
