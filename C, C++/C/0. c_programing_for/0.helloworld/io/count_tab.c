#include <stdio.h>

int	main(void)
{
	long	c, space=0, nl=0, tab=0;

	while ((c = getchar()) != EOF)
	{
		c == 32 ? space++ : 0;
		c == 9 ? tab++ : 0;
		c == 10 ? nl++ : 0;
	}
	printf("space: %lu, tab: %lu, nl: %lu\n", space, tab, nl);
}