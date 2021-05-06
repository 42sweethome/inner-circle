
#include "ft_push_swap.h"

void		under_2(t_link *st_a, t_info *info)
{
	t_circle	*tmp;

	if (st_a->head->value > st_a->head->next->value)
		func_sa(st_a, *info);
}

void		under_3(t_link *st_a, t_info *info)
{
	int		a;
	int		b;
	int		c;

	a = st_a->head->value;
	b = st_a->head->next->value;
	c = st_a->head->next->next->value;

	if (a > b && a > c)
		func_sa(st_a, *info);
	if (!(c > a && c > b))
	{
		func_ra(st_a);
		func_sa(st_a, *info);
		func_rra(st_a);
	}
	if ((a > c && a < b) || (a < c && a > b) || (a > b && b > c))
		func_sa(st_a, *info);
}

int		exit_a(t_link *st_a, int range, t_info *info)
{
	if (range == 2)
	{
		info->len_a = 2;
		under_2(st_a, info);
		return (1);
	}
	else if (range == 3)
	{
		info->len_a = 3;
		under_3(st_a, info);
		return (1);
	}
	return (0);
}
