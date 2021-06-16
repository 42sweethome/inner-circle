#include "../includes/pushswap.h"

int		main(int argc, char **argv)
{
	if (argc <= 1)
			return (0);
	int count;
	int	*stack;
	t_pivot pv;
	t_deq	a;
	t_deq	b;
	t_dsp	dsp;

	dsp_init(&dsp);
	if((count = ft_count_arg(argv, ' ')) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack = ft_get_sortstack(argc, argv, count);
	stack = ft_check_dup(stack, count);
	if (stack == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_init(&a, &b);
	ft_create_deq(stack, &a, count);
	ft_get_pivot(stack, &pv, count);
	divide_ra(&a, &b, pv, count, dsp);
	
//write(1, "main\n", 5);
	dsp_init(&dsp);
	print_deq(&a, &b, dsp);
	return (0);
}
