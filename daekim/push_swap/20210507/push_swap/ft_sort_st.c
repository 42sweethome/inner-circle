
#include "ft_push_swap.h"

int			sort_st(t_link *st_a, t_link *st_b, t_info *info)
{
	int		*num;
	int		size;
	int		pivot[3];

	size = input_arr(st_a, &num);
	if (size == 0)
		return (0);
	quick_sort(num, 0, size - 1);
	first_pivot(num, pivot, size);
	first_div(st_a, st_b, pivot, info);
	sort_a(st_a, st_b, info->len_a/*info->ra*/);
	sort_b(st_a, st_b, info->pb);
	sort_b(st_a, st_b, info->rb);
	return (1);
}
