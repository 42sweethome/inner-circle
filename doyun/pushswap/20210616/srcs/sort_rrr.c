/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:10 by doyun             #+#    #+#             */
/*   Updated: 2021/06/15 20:20:17 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	divide_rrr(t_deq *a, t_deq *b, t_dsp dsp)
{
//	printf("start rrr\n");
	int		count;

	count = 0;
	if (dsp.ra > dsp.rb)
	{
		count = dsp.ra - dsp.rb;
		while (count--)
		{
//printf("ra %d rb %d\n",dsp.ra,dsp.rb);
			rra(a);
		}
		count = dsp.rb;
	}
	else
	{

		count = dsp.rb - dsp.ra;
//		printf("count : %d\n", count);
//		write(1 ,"here \n" , 6);
		while (count--)
		{
//		printf("ra %d rb %d\n",dsp.ra,dsp.rb);
			rrb(b);
		}
		count = dsp.ra;
	}
	while (count--)
	{
		//printf("dsp.ra : %d dsp.rb : %d count %d\n", dsp.ra, dsp.rb , count);
		rrr(a, b);
	}
//	write(1,"finish rrr\n", 11);
}
