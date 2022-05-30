#include <stdio.h>

int	main(void)
{
	int i;
	int j = 15;
	for (i = 0; i < 10; i++)
	{
		printf("hello\n");
		for (j = i; j < i+1; j++)
		{
			printf("!");
		}
		
	}
	
}