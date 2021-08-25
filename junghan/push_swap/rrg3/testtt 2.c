#include <stdio.h>

typedef struct		s_node
{
	int		v1;
	int		v2;
}					t_node;

typedef struct		s_circle
{
	t_node		*num1;
	t_node		*num2;
}					t_circle;

typedef struct		s_link
{
	t_circle		*a;
	t_circle		*b;
}					t_link;

void pa(t_circle *a, t_circle *b)
{
	a->num1->v1 = a->num1->v2;
	b->num1->v1 = b->num1->v2;
}

void change1(t_link *link)
{
	pa(link->a, link->b);
}

/*
void change2(t_line *link)
{
	pa(&link->a, &link->b);
}
*/
int main()
{
	t_link link;

	link.a->num1->v1 = 0;
	link.a->num1->v2 = 1;
	link.b->num1->v1 = 0;
	link.b->num1->v2 = 1;

	change1(&link);
//	change2(&link);

	printf("a v1%d a v2%d\n",	link.a->num1->v1 ,	link.a->num1->v2);
	printf("b v1%d b v2%d\n",  	link.b->num1->v1, 	link.b->num1->v2);
}
