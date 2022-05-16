#include <stdio.h>

int	main(void)
{
	_Bool	a = 1;
	_Bool	b = 1;
	_Bool result;

	result = a && b;
	printf("%d\n", result);

	return (0);
}