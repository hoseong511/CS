#include <stdio.h>

int	main(void)
{
	float	f, c;
	
	f = 0;
	printf("화씨에서 섭씨\n");
	while (f <= 300)
	{
		c = 5.0/9.0 * (f - 32.0);
		printf("%3.0f %6.1f\n", f, c);
		f += 20;
	}
	printf("\n섭씨에서 화씨\n\n");
	while (c >= -18)
	{
		f = 9.0/5.0 * c + 32;
		printf("%5.1f %6f\n", c, f);
		c = 5.0/9.0 * ((f - 20) - 32.0);
	}
	return (0);
}