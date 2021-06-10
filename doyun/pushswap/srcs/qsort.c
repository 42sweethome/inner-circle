/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:28 by doyun             #+#    #+#             */
/*   Updated: 2021/06/10 15:11:53 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int			*ft_get_sortstack(int argc, char **argv, int count)
{
	int		*stack;
	char	**split;
	int		i;
	int		j;
	int		idx;

	i = 1;
	idx = 0;
	stack = (int *)ft_calloc(sizeof(int), count);
	while (i < argc && (split = ft_split(argv[i], ' ')) != NULL)
	{
		j = 0;
		while (idx < count && split[j])
		{
			stack[idx++] = ft_atoi(split[j]);
			j++;
		}
		i++;
	}
	return (stack);
}

void			ft_quick_sort(int *stack, int start, int end)
{
	int pivot;
	int i;
	int j;
	int temp;

	pivot = start;
	i = pivot + 1;
	j = end;
	if (start >= end)
		return ;	
	i = 0;
	while (i <= j)
	{
		while (i <= end && stack[i] <= stack[pivot])
			i++;
		while (j > start && stack[j] >= stack[pivot])
			j--;
		if (i > j)
		{
			temp = stack[pivot];
			stack[pivot] = stack[j];
			stack[j] = temp;
		}
		else
		{
			temp = stack[i];
			stack[i] = stack[j];
			stack[j] = temp;
		}
	}
	ft_quick_sort(stack, start, j - 1);
	ft_quick_sort(stack, j + 1, end);
}



