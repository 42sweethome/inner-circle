/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:05:21 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/17 15:56:39 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		dsp_init(t_dsp *dsp)
{
	dsp->ra = 0;
	dsp->pb = 0;
	dsp->rb = 0;
	dsp->pa = 0;
	dsp->rrb = 0;
	dsp->rra = 0;
}

void		ft_get_pivot(int *stack, t_pivot *pv, int count)
{
	if (count > 2)
	{
		ft_quick_sort(stack, 0, count - 1);
		pv->p1 = stack[count / 3];
		pv->p2 = stack[2 * count / 3];
	}
	free(stack);
	stack = NULL;
}

int			ft_get_npivot(int *stack, int count)
{
	int		pivot;

	ft_quick_sort(stack, 0, count);
	pivot = stack[count / 2];
	return (pivot);
}

int			ft_count_arg(char **s, char c)
{
	int		count;
	int		idx;
	int		idx2;

	count = 0;
	idx = 1;
	idx2 = 0;
	while (s[idx] != NULL)
	{
		while (s[idx][idx2] != '\0')
		{
			while (s[idx][idx2] == c)
				idx2++;
			while (s[idx][idx2] != c && s[idx][idx2])
			{
				idx2++;
				if (s[idx][idx2] == c || !(s[idx][idx2]))
					count++;
			}
		}
		idx++;
		idx2 = 0;
	}
	return (count);
}

int			*put_stack(t_node *deq, int count)
{
	int		*stack;
	int		idx;

	if (count <= 0)
		return (NULL);
	idx = -1;
	stack = (int *)ft_calloc(sizeof(int), count);
	while (++idx < count)
	{
		stack[idx] = deq->value;
		deq = deq->next;
	}
	return (stack);
}
