
#include "ft_push_swap.h"

int		check_order(t_link *st_a)
{
	t_circle	*tmp;

	tmp = st_a->head;
	while (tmp->next)
	{
		if (tmp->value >= tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		check_sort(t_link *st_a, t_info *info)
{
	int	ret;

	ret = check_order(st_a);
	if (ret == 1)
		return (1);
	if (info->len_a < 2)
		return (1);
	else if (info->len_a < 4)
	{
		ret = exit_a(st_a, info->len_a, info);
		if (ret == 1)
			return (1);
	}
	return (0);
}
