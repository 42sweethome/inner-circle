/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:03:23 by junghan           #+#    #+#             */
/*   Updated: 2020/12/28 15:02:09 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*result;
	t_list	*new;

	if (!lst)
		return (0);
	tmp = lst;
	if (!(result = ft_lstnew(f(tmp->content))))
		return (0);
	tmp = tmp->next;
	while (tmp)
	{
		if (!(new = ft_lstnew(f(tmp->content))))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new);
		tmp = tmp->next;
	}
	return (result);
}
