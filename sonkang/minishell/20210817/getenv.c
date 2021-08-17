#include <stdlib.h>
#include <stdio.h>



int main(int ac, char **av)
{
	printf("key = %s , value = %s\n", av[1], getenv((const char *)av[1]));
	while (1);
	return (0);
}
