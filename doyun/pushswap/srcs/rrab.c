#include "../includes/pushswap.h"

void		rra(t_deq *a)
{
	t_node	*temp;

	if (a->head != NULL && a->head->next != NULL)
	{
		temp = a->tail->prev;
		temp->next = NULL;
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->tail->prev = NULL;
		a->head = a->tail;
		a->tail = temp;
//		write(1, "rra\n", 4);
	}
}

void		rrb(t_deq *b)
{
	t_node	*temp;

	if (b->head != NULL && b->head->next != NULL)
	{
		temp = b->tail->prev;
		temp->next = NULL;
		b->tail->next = b->head;
		b->head->prev = b->tail;
		b->tail->prev = NULL;
		b->head = b->tail;
		b->tail = temp;
//		write(1, "rrb\n", 4);
	}
}

void		rrr(t_deq *a, t_deq *b)
{
	t_node	*temp;

	if ((a->head != NULL && a->head->next != NULL) && 
		(b->head != NULL && b->head->next != NULL))
	{
		temp = a->tail->prev;
		temp->next = NULL;
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->tail->prev = NULL;
		a->head = a->tail;
		a->tail = temp;
		temp = b->tail->prev;
		temp->next = NULL;
		b->tail->next = b->head;
		b->head->prev = b->tail;
		b->tail->prev = NULL;
		b->head = b->tail;
		b->tail = temp;
	//	write(1, "rrr\n", 4);
	}
}
