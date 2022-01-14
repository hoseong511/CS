#include <stdio.h>

int	main(void)
{
	int	c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		c == '\n' ? nl++ : 1;
	printf("%d\n", nl);
}