/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:05:08 by junghan           #+#    #+#             */
/*   Updated: 2021/04/23 15:59:50 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct	s_circle
{
	struct s_circle *next;
	struct s_circle *pre; //have to do
	int	value;
}				t_circle;

typedef struct	s_link
{
	t_circle	*head;
	t_circle	*tail;
	t_circle	*node;
}				t_link;

void		lstadd_back(t_circle **lst, t_circle *new);
t_circle	*lstnew(int content);
int		input_int(t_link *st_a, char *s, char c);
void	quick_sort(int *st_a, int *st_b, int start, int end);
#endif
