#include <stdlib.h>
#include <stdio.h>



int main(int ac, char **av)
{
	printf("key = %s , value = %s", av[1], getenv((const char *)av[1]));

	return (0);
}
