#include <stdio.h>

int	tmult_ok(int x, int y)
{
	int	p = x*y;

	return !x || p/x == y;
}

int	main(void)
{
	int	x = __INT_MAX__;
	int y = __INT_MAX__;

	if (tmult_ok(x, y))
		printf("tmult_ok: %d\n", x * y);
	else
		printf("%d\n", x * y);
}