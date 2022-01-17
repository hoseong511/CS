#include <stdio.h>

#define	ASCII 128

int	main(void)
{
	int	c, i;
	int	nascii[ASCII];

	for (i = 0; i < ASCII; i++)
		nascii[i] = 0;
	while ((c = getchar()) != EOF)
		++nascii[c];
	for (i = 0; i < ASCII; i++)
	{
		if (nascii[i] > 0)
			printf("%c : %d\n", i, nascii[i]);
	}
	return (0);
}