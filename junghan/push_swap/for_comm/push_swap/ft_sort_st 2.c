/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:24:55 by junghan           #+#    #+#             */
/*   Updated: 2021/05/16 11:25:21 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			sort_st(t_link *st_a, t_link *st_b, t_info *info)
{
	int		*num;
	int		size;
	int		pivot[3];

	size = input_arr(st_a, &num);
	if (size == 0)
		return (-1);
	quick_sort(num, 0, size - 1);
	first_pivot(num, pivot, size);
	first_div(st_a, st_b, pivot, info);
	sort_a(st_a, st_b, info->len_a);
	sort_b(st_a, st_b, info->pb);
	sort_b(st_a, st_b, info->rb);
	return (1);
}
