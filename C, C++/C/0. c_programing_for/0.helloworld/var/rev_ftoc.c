#include <stdio.h>

int	main(void)
{
	float	f;
	
	printf("300 화씨에서 섭씨\n\n");
	for (f = 300; f >= 0; f -= 20)
		printf("%3.0f %6.1f\n", f, 5.0/9.0 * (f - 32.0));
	return (0);
}