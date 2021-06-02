/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:05:21 by doyun             #+#    #+#             */
/*   Updated: 2021/06/01 17:26:40 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		ft_is_num(char num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int		ft_count_arg(char **s, char c)
{
	int			count;
	int			idx;
	int			idx2;

	count = 0;
	idx = 1;
	idx2 = 0;
	while (s[idx] != NULL)
	{
		while (s[idx][idx2] != '\0')
		{
			while (s[idx][idx2] == c)
				idx2++;
			while (s[idx][idx2] != c && s[idx][idx2])
			{
				idx2++;
				if (s[idx][idx2] == c || !(s[idx][idx2]))
					count++;
			}
		}
		idx++;
		idx2 = 0;
	}
	return (count);
}
