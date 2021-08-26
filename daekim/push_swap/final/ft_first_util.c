/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:36:41 by daekim            #+#    #+#             */
/*   Updated: 2021/05/23 12:36:42 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	first_div(t_link *st_a, t_link *st_b, int pivot[2], t_info *info)
{
	int		tmp_len;

	tmp_len = info->len_a;
	if (tmp_len <= 3)
		return ;
	while (tmp_len-- > 0)
	{
		if (st_a->head->value < pivot[LARGE])
		{
			func_pb(st_a, st_b, info);
			if (st_b->head->value < pivot[SMALL])
			{
				func_rb(st_b, info);
				info->rb++;
			}
			else
				info->pb++;
		}
		else
		{
			func_ra(st_a, info);
			info->ra++;
		}
	}
}

void	first_pivot(int *num, int pivot[2], int size)
{
	pivot[SMALL] = num[size / 3];
	pivot[LARGE] = num[size * 2 / 3];
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
