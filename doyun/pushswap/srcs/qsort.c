/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:28 by doyun             #+#    #+#             */
/*   Updated: 2021/06/01 13:02:02 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		ft_changespot()
{
	
}

void		ft_quick_sort()
{

}



char		*ft_get_pivot(char **argv, int count)
{
	int		*stack;
	char	**split;
	int		i;
	int		j;

	printf("in pivot\n");
	i = 0;
	stack = (int *)malloc(sizeof(int) * count + 1);
	stack[count] = '\0';
	while ((split = ft_split(argv[i + 1], ' ')) != NULL)
	{
		j = 0;
		while (split[j])
		{
			printf("%s\n",split[j]);
			stack[i + j] = ft_atoi(split[j]);
			printf("%d\n", stack[i + j]);
			j++;
		}
		i++;
	}
	i = 0;
	while(stack[i])
	{
		printf("dd\n");
		printf("%d\n",stack[i]);
		i++;
	}
	return (stack);
}
