#include <stdio.h>

#define ON 1
#define OFF 0

/* count line, words, and characters in input */
int	main(void)
{
	int	c, nl, nw, nc, state;

	state = OFF;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == OFF)
			{
				state = ON;
				printf("\n");
			}
		}
		else
		{
			state = OFF;
			printf("%c", c);
		}
	}
	return (0);
}