#include <stdio.h>
#include <limits.h>

long int	power(int base, long int n)
{
	long int	i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p *= base;
	return (p);
}

int	main(void)
{
	long int	max, min;

	max = min = 0;
	for (char i = 1; i != 0; i++)
	{
		if (i > max)
			max = i;
		if (i < min)
			min = i;
	}
	printf("char -> max : %ld, min : %ld\n", max, min);

	// for (int i = 1; i != 0; i++)
	// {
	// 	if (i > max)
	// 		max = i;
	// 	if (i < min)
	// 		min = i;
	// }
	// printf("int -> max : %ld, min : %ld\n", max, min);
	long int a = sizeof(char);
	long int bit = a * 8;
	printf("sizeof(char) : %ld\n", a);
	printf("char -> max : %ld, min : %ld\n", power(2, bit -1) - 1, -power(2, bit -1));

	a = sizeof(int);
	bit = a * 8;
	printf("sizeof(int) : %ld\n", a);
	printf("int -> max : %ld, min : %ld\n", power(2, bit -1) - 1, -power(2, bit -1));

	a = sizeof(short int);
	bit = a * 8;
	printf("sizeof(short int) : %ld\n", a);
	printf("short int -> max : %ld, min : %ld\n", power(2, bit -1) - 1, -power(2, bit -1));

	a = sizeof(unsigned int);
	bit = a * 8;
	printf("sizeof(unsigned int) : %ld\n", a);
	printf("unsigned int -> max : %ld, min : %d\n", power(2, bit) - 1, 0);

	a = sizeof(long int);
	bit = a * 8;
	printf("sizeof(long int) : %ld\n", a);
	printf("long int -> max : %ld, min : %ld\n", power(2, bit-1) - 1, power(2, bit-1));

	return (0);
}
