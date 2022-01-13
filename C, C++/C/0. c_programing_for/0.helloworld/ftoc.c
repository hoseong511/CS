#include <stdio.h>

int	main(void)
{
	float	f, c;
	
	f = 0;
	while (f <= 300)
	{
		c = 5.0/9.0 * (f - 32.0);
		printf("%3.0f %6.1f\n", f, c);
		f += 20;
	}
	return (0);
}