/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <doyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:45:53 by doyun             #+#    #+#             */
/*   Updated: 2021/02/02 18:59:43 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_free(t_list *f_lst, void (*del)(void *))
{
	if (!f_lst)
	{
		del(f_lst->content);
		free(f_lst);
	}
	return (f_lst);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_lst;
	t_list	*new_lst;
	t_list	*temp_lst;

	if (!lst || !f)
		return (NULL);
	temp_lst = lst;
	if (!(f_lst = ft_lstnew(f(temp_lst->content))))
		return (NULL);
	temp_lst = temp_lst->next;
	while (temp_lst)
	{
		if (!(new_lst = ft_lstnew(f(temp_lst->content))))
		{
			ft_lstclear(&f_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&f_lst, new_lst);
		temp_lst = temp_lst->next;
	}
	return (f_lst);
}
