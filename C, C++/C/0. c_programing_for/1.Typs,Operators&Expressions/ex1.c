#include <stdio.h>
#include <limits.h>
#include <float.h>

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
		{
			min = i;
			break;
		}
	}
	printf("char -> max : %ld, min : %ld\n", max, min);

	long int a = sizeof(char);
	long int bit = a * 8;
	printf("sizeof(char) : %ld\n", a);
	printf("char -> max : %ld, min : %ld\n", power(2, bit -1) - 1, -power(2, bit -1));
	printf("char -> max : %d, min : %d\n", CHAR_MAX, CHAR_MIN);

	a = sizeof(int);
	bit = a * 8;
	printf("sizeof(int) : %ld\n", a);
	printf("int -> max : %ld, min : %ld\n", power(2, bit -1) - 1, -power(2, bit -1));
	printf("INT -> max : %d, min : %d\n", INT_MAX, INT_MIN);

	a = sizeof(short int);
	bit = a * 8;
	printf("sizeof(short int) : %ld\n", a);
	printf("short int -> max : %ld, min : %ld\n", power(2, bit -1) - 1, -power(2, bit -1));
	printf("SHRT -> max : %d, min : %d\n", SHRT_MAX, SHRT_MIN);

	a = sizeof(unsigned int);
	bit = a * 8;
	printf("sizeof(unsigned int) : %ld\n", a);
	printf("unsigned int -> max : %ld, min : %d\n", power(2, bit) - 1, 0);
	printf("UINT -> max : %d, min : %d\n", UINT_MAX, 0);

	a = sizeof(long int);
	bit = a * 8;
	printf("sizeof(long int) : %ld\n", a);
	printf("long int -> max : %ld, min : %ld\n", power(2, bit-1) - 1, power(2, bit-1));
	printf("LONG -> max : %ld, min : %ld\n", LONG_MAX, LONG_MIN);

	printf("FLT_MAX_EXP : %d, FLT_MIN_EXP : %d \n", FLT_MAX_EXP, FLT_MIN_EXP);
	printf("FLT_MAX : %f, FLT_MIN : %f \n", FLT_MAX, FLT_MIN);
	printf("DBL_MAX_EXP : %d, DBL_MIN_EXP : %d \n", DBL_MAX_EXP, DBL_MIN_EXP);
	printf("DBL_MAX : %f, DBL_MIN : %f \n", DBL_MAX, DBL_MIN);

	return (0);
}
