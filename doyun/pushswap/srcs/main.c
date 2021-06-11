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
	//t_dsp   dsp;

	count = ft_count_arg(argv, ' ');
	stack = ft_get_sortstack(argc, argv, count);
	if (stack == NULL)
	{
		write(1, "ERROR\n", 6);
		return(0);
	}
	ft_init(&a, &b);
	ft_create_deq(stack, &a, count);
	ft_get_pivot(stack, &pv, count);
	divide_ra(&a, &b, pv, count);
	//dsp_init(&dsp);
//	print_deq(&a, &b, dsp);
	return (0);
}
