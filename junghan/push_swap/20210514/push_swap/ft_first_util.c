/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:31:12 by junghan           #+#    #+#             */
/*   Updated: 2021/05/12 19:42:41 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		pre_div_st(t_link *st_a, int *tmp_len, int range, t_info *info)
{
	*tmp_len = range;
	if (range <= 3)
	{
		exit_a(st_a, range, info);
		return (1);
	}
	return (-1);
}

void	first_div(t_link *st_a, t_link *st_b, int pivot[3], t_info *info)
{
	int		i;
	int		tmp_len;

	i = pre_div_st(st_a, &tmp_len, info->len_a, info);
	if (i == 1)
		return ;
	while (++i < tmp_len)
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
