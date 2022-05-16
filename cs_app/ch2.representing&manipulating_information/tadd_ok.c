#include <stdio.h>

int	tadd_ok(int x, int y)
{
	int	tmp;
	tmp = x + y;
	if (x > 0 && y > 0 && tmp <= 0)
		return 0;
	else if (x < 0 && y < 0 && tmp >= 0)
		return 0;
	else
		return 1;
}

int	buggy_tadd_ok(int x, int y)
{
	int	sum = x + y;
	return (sum - x == y) && (sum -y == x);
}

int	main(void)
{
	int x = __INT_MAX__;
	int y = __INT_MAX__;
	if (tadd_ok(x, y))
		printf("tadd_ok: %d\n", x + y); 
	else 
		printf("overflow!: %d\n", x + y);
	if (buggy_tadd_ok(x, y))
		printf("tadd_ok: %d\n", x + y); 
	else 
		printf("overflow!: %d\n", x + y);
	
}