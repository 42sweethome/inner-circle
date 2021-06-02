#include "../includes/pushswap.h"

int		main(int argc, char **argv)
{
	if (argc == 0)
		return (-1);
	int count;
	int	*stack;
	t_pivot pv;
	t_deq	a;
	t_deq	b;

	count = ft_count_arg(argv, ' ');
	stack = ft_get_sortstack(argc, argv, count);
	ft_init(&a, &b);
	ft_create_deq(stack, &a, count);
	ft_get_pivot(stack, &pv, count);
	divide_a(&a, &b, pv, count);
	return (0);
}
