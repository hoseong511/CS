#include <stdio.h>

int	power(int, int); 
// base, n은 함수 내에서만 사용되는 변수 이름이므로 호출할 때는 다른 이름으로 사용 가능.

int	main(void)
{
	int	i;

	for (i = 0; i < 10; i++)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	return (0);
}

int power(int base, int n)
{
	int	i, p;

	p = 1;
	for (i = 1; i <= n; i++)
		p *= base;
	return (p);
}