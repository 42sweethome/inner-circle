/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:03:10 by doyun             #+#    #+#             */
/*   Updated: 2021/06/15 20:19:39 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		divide_ra(t_deq *a, t_deq *b, t_pivot pv, int count, t_dsp pdsp)
{
//	printf("\nstart ra\n");
	t_dsp dsp;
	int i;
	int	*stack;
	int	check;

	i = 0;
	check = 0;
	if (ft_check_ahead(a, count))
	{
		//pb에서 pa 한거 정렬 끝나면 ra한것 올려서 정렬
		//if (pdsp.ra || pdsp.rb)
	//	{
	//		divide_rrr(a, b, pdsp);
	//		if (ft_check_ahead(a, pdsp.ra))
					return ;
//		}
	//	else
	//		return ;
	//	if (pdsp.ra)
	//		divide_ra(a, b, pv, pdsp.ra, pdsp);

	}
	if (count <= 6)
	{
		check = sort_case(a, b, count);
//		printf("******************dsp.ra : %d\n",pdsp.ra);
	/*	while(pdsp.ra--)
			rra(a);*/		
		if (check == 0)
		{
	//		if (pdsp.ra || pdsp.rb)
	//			divide_rrr(a, b, pdsp);
	//		else
				return ;
	//		if (pdsp.ra <= 6)
	//		{
	//			check = sort_case(a, b, pdsp.ra);
	//			return ;
	//		}
	//		if (pdsp.ra)
	//			divide_ra(a, b, pv, pdsp.ra, pdsp);
		}
		//pb에서 pa 한거 정렬 끝나면 ra한것 올려서 정렬
	}

	dsp_init(&dsp);
	while(i < count)
	{
		if (a->head->value >= pv.p2) 	
		{
			ra(a);
			dsp.ra++;
		}
		else if (a->head->value < pv.p1) 
		{
			pb(b, a);
			dsp.pb++;	
		//	pb(b, a);
		//	rb(b);
		//	dsp.rb++;
		}
		else 
		{
		//	pb(b, a);
		//	dsp.pb++;	
			pb(b, a);
			rb(b);
			dsp.rb++;
		}
		i++;
//		printf("pivot : %d %d\n",pv.p1, pv.p2);
//		print_deq(a, b, dsp);
	}
//	printf("----------------------------finish ra\n");
//		printf("@@@@@@@@@@@@@@@@@@@@@@@@@dsp.ra : %d dsp.rb : %d count %d\n", dsp.ra, dsp.rb , count);

	if (dsp.ra || dsp.rb)
	{
			divide_rrr(a, b, dsp);
	}
	stack = put_stack(a->head, dsp.ra);
//	show(stack, dsp.ra);//
	ft_get_pivot(stack, &pv, dsp.ra);
	divide_ra(a, b, pv, dsp.ra, dsp);

	stack = put_stack(b->head, dsp.rb);
//	show(stack, dsp.rb);//
	ft_get_pivot(stack, &pv, dsp.rb);
	divide_pb(a, b, pv, dsp.rb);
	
	stack = put_stack(b->head, dsp.pb);
//	show(stack, dsp.pb);//
	ft_get_pivot(stack, &pv, dsp.pb);
	divide_pb(a, b, pv, dsp.pb);
}
