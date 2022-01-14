#include <stdio.h>

#define ON 1
#define OFF 0

int	main(void)
{
	int	c, check = OFF;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (check == OFF)
			{
				check = ON;
				putchar(c);
			}
		}
		else
		{
			check = OFF;
			putchar(c);
		}
	}
	return (0);
}