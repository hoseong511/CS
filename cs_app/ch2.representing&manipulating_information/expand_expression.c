#include "show_byte.h"
#include <limits.h>

int	fun1(unsigned word)
{
	int	 tmp;
	unsigned utmp;

	utmp = word << 24;
	tmp = (int) (utmp >> 24);
	return tmp;
}

int	fun2(unsigned word)
{
	int	 tmp;
	
	tmp = (int) word << 24;
	tmp = tmp >> 24;
	return tmp;
}

int main(void)
{
	short	sx = -12345;
	unsigned short	usx = sx; // 묵시적 변환
	int	x = sx;
	unsigned	ux = usx;

	printf("sx  = %d:\t", sx);
	show_bytes((byte_pointer) &sx, sizeof(short));
	printf("usx  = %u:\t", usx);
	show_bytes((byte_pointer) &usx, sizeof(unsigned short));
	printf("x  = %d:\t", x);
	show_bytes((byte_pointer) &x, sizeof(int));
	printf("ux  = %u:\t", ux); 
	show_bytes((byte_pointer) &ux, sizeof(unsigned int)); 

	unsigned uy = sx; // 자료형 크기를 먼저 바꾸고 unsigned 처리
	printf("uy = %u:\t", uy);
	show_bytes((byte_pointer) &uy, sizeof(unsigned int)); 

	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("fun1(0x00000076) : %X\n", fun1(0x00000076));
	printf("fun2(0x00000076) : %X\n", fun2(0x00000076));

	printf("fun1(0x87654321) : %X\n", fun1(0x87654321));
	printf("fun2(0x87654321) : %X\n", fun2(0x87654321));

	printf("fun1(0x000000C9) : %X\n", fun1(0x000000C9));
	printf("fun2(0x000000C9) : %X\n", fun2(0x000000C9));

	printf("fun1(0xEDCBA987) : %X\n", fun1(0xEDCBA987));
	printf("fun2(0xEDCBA987) : %X\n", fun2(0xEDCBA987));

	printf("fun1(0x000000E6) : %X\n", fun1(0x000000E6));
	printf("fun2(0x000000E6) : %X\n", fun2(0x000000E6));

	int	a = __INT_MAX__ ;
	long long b = __LONG_LONG_MAX__;
	unsigned ua = __INT_MAX__ * 2U + 1U;
	unsigned long long	ub = __LONG_LONG_MAX__ * 2ULL + 1ULL;
	a++;
	b++;
	ua++;
	ub++;
	printf("INT_MAX + 1: %d \n", a);
	printf("LLONG_MAX + 1: %lld \n", b);
	printf("UINT_MAX + 1: %u \n", ua);
	printf("ULONGLONG_MAX + 1: %lld \n", ub);
}
