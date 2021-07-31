/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 02:12:37 by doyun             #+#    #+#             */
/*   Updated: 2021/02/02 19:04:00 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_lst;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp_lst = *lst;
	while (temp_lst->next)
	{
		temp_lst = temp_lst->next;
	}
	temp_lst->next = new;
}
