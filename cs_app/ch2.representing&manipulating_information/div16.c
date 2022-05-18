#include <stdio.h>
#include <time.h>

int	div16(int x)
{
	int	bias = (x >> 31) & 0xf;
	return ((bias + x) >> 4);
}
int div16_test(int x)
{
	return (x / 16);
}

int	main(void)
{
	clock_t start1, end1, start2, end2;
	clock_t	res1, res2;
	int div;

	start1 = clock();
	div  = (123456789) & 32767;
	end1 = clock();
	res1 = (end1 - start1);

	start2 = clock();
	div = (123456789) % 32768;
	end2 = clock();
	res2 = (end2 - start2); // 컴파일러가 알아서 최적화 하는둣하다. 
	// printf("x = %d , %d\n", -16, div16(-16));
	// printf("x = %d , %d\n", (1 << 31) + 2, div16((1 << 31) + 2));
	// printf("x = %d , %d\n", (1 << 31) + 2, ((1 << 31) + 2) / 16);
}
