#include "../includes/pushswap.h"

void		ra(t_deq *a)
{
	t_node	*temp;

	if (a->head == NULL || a->head->next == NULL)
		return ;
	temp = a->head->next;
	temp->prev = NULL;
	a->tail->next = a->head;
	a->head->prev = a->tail;
	a->tail = a->head;
	a->tail->next = NULL;
	a->head = temp;
	write(1, "ra\n", 3);
}

void		rb(t_deq *b)
{
	t_node	*temp;

	if (b->head == NULL || b->head->next == NULL)
		return ;
	temp = b->head->next;
	temp->prev = NULL;
	b->tail->next = b->head;
	b->head->prev = b->tail;
	b->tail = b->head;
	b->tail->next = NULL;
	b->head = temp;
	write(1, "rb\n", 3);
}

void		rr(t_deq *a, t_deq *b)
{
	t_node	*temp;

	if ((a->head != NULL && a->head->next != NULL) && 
			(b->head != NULL && b->head->next != NULL))
	{
		temp = a->head->next;
		temp->prev = NULL;
		a->tail->next = a->head;
		a->head->prev = a->tail;
		a->tail = a->head;
		a->tail->next = NULL;
		a->head = temp;
		temp = b->head->next;
		temp->prev = NULL;
		b->tail->next = b->head;
		b->head->prev = b->tail;
		b->tail = b->head;
		b->tail->next = NULL;
		b->head = temp;
		write(1, "rr\n", 3);
	}
}
