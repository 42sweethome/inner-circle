/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:28 by doyun             #+#    #+#             */
/*   Updated: 2021/06/22 12:45:19 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		ft_free_split(char **split, int idx)
{
	if (split == NULL)
		return ;
	else if (*split == NULL)
		return ;
	while (idx > 0)
	{
		idx--;
		free(split[idx]);
		split[idx] = 0;
	}
	free(split);
	split = 0;
}

void		ft_var_init(int *idx, int *flag)
{
	idx[0] = 1;
	idx[2] = 0;
	*flag = 1;
}

int			*ft_get_sortstack(int argc, char **argv, int count)
{
	int		*stack;
	char	**split;
	int		idx[3];
	int		flag;

	ft_var_init(idx, &flag);
	stack = (int *)ft_calloc(sizeof(int), count);
	while (idx[0] < argc && (split = ft_split(argv[idx[0]], ' ')) != NULL)
	{
		idx[1] = 0;
		while (idx[2] < count && split[idx[1]])
		{
			stack[idx[2]++] = ft_atoi(split[idx[1]], &flag);
			if (flag == 0)
			{
				ft_free_split(split, idx[1]);
				free(stack);
				return (NULL);
			}
			idx[1]++;
		}
		idx[0]++;
		ft_free_split(split, idx[1]);
	}
	return (stack);
}

void		change_var(int i, int j, int *stack, int pivot)
{
	int		temp;

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

void		ft_quick_sort(int *stack, int start, int end)
{
	int		pivot;
	int		i;
	int		j;

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
		change_var(i, j, stack, pivot);
	}
	ft_quick_sort(stack, start, j - 1);
	ft_quick_sort(stack, j + 1, end);
}
