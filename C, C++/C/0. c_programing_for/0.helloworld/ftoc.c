#include <stdio.h>

#define	LOWER 0
#define	UPPER 300
#define	STEP 20

int	main(void)
{
	float	f, c;
	
	f = LOWER;
	printf("화씨에서 섭씨\n");
	while (f <= UPPER)
	{
		c = 5.0/9.0 * (f - 32.0);
		printf("%3.0f %6.1f\n", f, c);
		f += STEP;
	}
	printf("\n섭씨에서 화씨\n\n");
	while (c >= LOWER)
	{
		f = 9.0/5.0 * c + 32;
		printf("%5.1f %6.0f\n", c, f);
		c = 5.0/9.0 * ((f - STEP) - 32.0);
	}
	return (0);
}