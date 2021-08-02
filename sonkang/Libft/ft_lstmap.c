/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:23:52 by sonkang           #+#    #+#             */
/*   Updated: 2021/01/13 15:42:38 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*new;

	if (lst == 0 || f == 0)
		return (0);
	tmp = lst;
	if (!(new_lst = ft_lstnew(f(tmp->content))))
		return (0);
	tmp = tmp->next;
	while (tmp)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new);
		tmp = tmp->next;
	}
	return (new_lst);
}
