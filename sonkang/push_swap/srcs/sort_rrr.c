/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:10 by sonkang           #+#    #+#             */
/*   Updated: 2021/06/17 15:56:27 by sonkang          ###   ########.fr       */
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
