/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 02:32:27 by doyun             #+#    #+#             */
/*   Updated: 2021/02/02 22:56:46 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;

	if (!lst)
		return ;
	while (*lst)
	{
		temp_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp_lst;
	}
}
