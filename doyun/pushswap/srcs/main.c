#include "../includes/pushswap.h"

int		main(int argc, char **argv)
{
	if (argc == 0)
		return (-1);
	int count;
	int *pivot;
	int i = 0;
	
	count = ft_count_arg(argv, ' ');
	pivot = ft_get_pivot(argv, count);
	while (pivot[i])
	{
		printf("pivot : %d\n", pivot[i]);
		i++;
	}
/*	t_deq a;
	t_deq b;
	int	i;
	int j;
	char **split;
	
	if (argc == 0)
		return (-1);
	i = 1;
	ft_deq_init(&a, &b);
	ft_get_pivot(argc, argv);
	while (0 != (split = ft_split(argv[i], '\n')))
	{
		j = 0;
		while (split[j])
		{
			ft_create_deq(ft_atoi(split[j]), &a);
		//	ft_create_deq(ft_atoi(split[j]), &b);
			j++;
		}
		i++;
	}

	check = a.head;
	while (check != 0)
	{
		printf("check :%d\n", check->value);
		check = check->next;
	}
	rr(&a, &b);
	check = a.head;
	while(check != 0)
	{
		printf("ra : %d\n",check->value);
		check = check->next;
	}
	rrr(&a, &b);
	check = b.head;
	while(check != 0)
	{
		printf("rb : %d\n",check->value);
		check = check->next;
	}*/
	
	return (0);
}
