/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:28 by doyun             #+#    #+#             */
/*   Updated: 2021/06/01 20:38:29 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		ft_changespot()
{

}


int			*ft_get_pivot(char **argv, int count)
{
	int		*stack;
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	printf("%d\n",count);
	stack = (int *)ft_calloc(sizeof(int), count);
	while ((split = ft_split(argv[i + 1], ' ')) != NULL)
	{
		k = 0;
		while (split[k])
		{
			stack[i + j] = ft_atoi(split[k]);
			j++;
			k++; //j로stack split인덱스 둘다 올리면 다시 while밖에서 초기화 할 때 앞의 stack index도 초기화 됨
		}
		i++;
		j--;
	}
	i = 0;
	// stack에 split한 값이 잘 들어 갔는지 확인
	ft_quick_sort(stack, 0, count);
	i = 0;
	printf("stack2 : %d\n",stack[i]);
	return (stack);
}

void			ft_quick_sort(int *stack, int start, int end)
{
	int pivot;
	int i;
	int j;
	int temp;
	int c;

	c = 0;
//	printf("in quick\n");
	pivot = start;
	i = pivot + 1;
	j = end;
//	printf("end %d\n", end);
	if (start >= end)
		return ;	
	while (c < end)
	{
		//printf("ii : %d\n",stack[c]);
		c++;
	}
	i = 0;
	while (i <= j)
	{
		while (i <= end && stack[i] <= stack[pivot])
			i++;
		while (j > start && stack[j] >= stack[pivot])
			j--;
		if (i > j)
		{
			temp = stack[pivot];
			stack[pivot] = stack[j];
			stack[j] = temp;
			c = 0;
			while(c < end)
			{
			//	printf("if stack : %d\n",stack[c]);
				c++;
			}
		}
		else
		{
			temp = stack[i];
			stack[i] = stack[j];
			stack[j] = temp;
			c = 0;
			while (c < end)
			{
			//	printf("else stack : %d\n",stack[c]);
				c++;
			}
		}
	printf("i %d j %d\n",i, j);
	}
	c = 0;

	ft_quick_sort(stack, start, j - 1);
	ft_quick_sort(stack, j + 1, end);
}



