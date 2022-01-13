#include <stdio.h>

int	main(void)
{
	int	c;

	c = getchar();
	printf("EOF: %c %d\n", EOF, EOF);
	while (c != EOF)
	{
		// putchar(c);
		c = getchar();
		printf("%c: %d\n", c, c);
		printf("EOF? %d\n", c != EOF);
	}
}