#include "../includes/pushswap.h"

void		pa(t_deq *a, t_deq *b)
{
	t_node *temp;
//	printf("head : %d, tail : %d\n", a->head->value, a->tail->value);
	if (b->head == NULL)
		return ;
	temp = b->head->next;
	if (temp != NULL)
		temp->prev = NULL;
	if (a->head != NULL)
		a->head->prev = b->head;
	b->head->next = a->head;	
//	printf("head : %d, tail : %d\n", a->head->value, a->tail->value);
	a->head = b->head;	
//	printf("head : %d, tail : %d\n", a->head->value, a->tail->value);
	b->head = temp;
	if (temp == NULL)
		b->tail = b->head;
	if (a->tail == NULL)
		a->tail = a->head;	
//	printf("head : %d, tail : %d\n", a->head->value, a->tail->value);
	write(1, "pa\n", 3);
}

void		pb(t_deq *b, t_deq *a)
{
	t_node *temp;

	if (a->head == NULL)
		return ;
	temp = a->head->next;
	if (temp != NULL)
		temp->prev = NULL;
	if (b->head != NULL)
		b->head->prev = a->head;
	a->head->next = b->head;
	b->head = a->head;
	a->head = temp;
	if (temp == NULL)
		a->tail = a->head;
	if (b->tail == NULL)
		b->tail = b->head;
	write(1, "pb\n", 3);
}
