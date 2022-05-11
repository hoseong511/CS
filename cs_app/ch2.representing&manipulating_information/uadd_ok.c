#include <stdio.h>

int	uadd_ok(unsigned x, unsigned y)
{
	if (x + y >= x)
		return 1;
	return 0;
}

int	main(void)
{
	unsigned a, b; 

	scanf("%u %u", &a, &b);

	if (uadd_ok(a, b))
		printf("uadd_ok : %u\n", a+b);
	else
		printf("uadd_fail: %u\n", a+b);
	while (1)
		;
}
