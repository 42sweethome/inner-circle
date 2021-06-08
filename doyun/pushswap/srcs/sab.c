#include "../includes/pushswap.h"

void		sa(t_deq *a)
{
	t_node	*temp;
	printf("head : %d, tail : %d\n", a->head->value, a->tail->value);
	if (a->head != NULL && a->head->next != NULL)
	{
		temp = a->head->next;	
		a->head->next = temp->next;
		if (temp->next == NULL)
			a->tail = a->head;
		temp->next = a->head;	
		a->head->prev = temp;	
		temp->prev = NULL;	
		a->head = temp;	
		write(1, "sa\n", 3);
	}
}

void		sb(t_deq *b)
{
	t_node	*temp;

	if (b->head != NULL && b->head->next != NULL)
	{
		temp = b->head->next;
		b->head->next = temp->next;
		if (temp->next == NULL)
			b->tail = b->head;
		temp->next = b->head;
		b->head->prev = temp;
		temp->prev = NULL;
		b->head = temp;
		write(1, "sb\n", 3);
	}
}

void		ss(t_deq *a, t_deq *b)
{
	t_node	*temp;

	if ((a->head == NULL || a->head->next == NULL) && 
			(b->head == NULL || b->head->next == NULL))
	{
		temp = a->head->next;
		a->head->next = temp->next;
		temp->next = a->head;
		a->head->prev = temp;
		temp->prev = NULL;
		a->head = temp;
		temp = b->head->next;
		b->head->next = temp->next;
		temp->next = b->head;
		b->head->prev = temp;
		temp->prev = NULL;
		b->head = temp;
		write(1, "ss\n", 3);
	}
}
