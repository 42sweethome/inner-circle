/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:10 by doyun             #+#    #+#             */
/*   Updated: 2021/06/16 16:48:42 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void		divide_rrr(t_deq *a, t_deq *b, t_dsp dsp)
{
	int		count;

	count = 0;
	if (dsp.ra > dsp.rb)
	{
		count = dsp.ra - dsp.rb;
		while (count--)
			rra(a);
		count = dsp.rb;
	}
	else
	{
		count = dsp.rb - dsp.ra;
		while (count--)
			rrb(b);
		count = dsp.ra;
	}
	while (count--)
		rrr(a, b);
}
