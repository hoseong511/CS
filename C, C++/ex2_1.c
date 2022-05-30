#include <limits.h>
#include <stdio.h>

int main(void)
{
	char	tc = 1;
	unsigned char	tu = 1;
	short	ts = 1;
	unsigned short	us = 1;
	int		t = 1;
	unsigned long u = 1UL;
	long	tl = 1L;
	unsigned long	ul = 1UL;

	tc = tc << 7;
	printf("min char_t = %d, ", tc);
	tc = tc - 1;
	printf("max char_t = %d\n", tc);
	tu = tu << 8;
	printf("min char_u = %d, ", tu);
	tu = tu - 1;
	printf("max char_u = %d\n", tu);

	printf("%050d %s\n", 0, "-> short");
	ts = ts << 15;
	printf("min short_t = %d, ", ts);
	ts = ts - 1;
	printf("max short_t = %d\n", ts);
	us = us << 16;
	printf("min short_u = %d, ", us);
	us = us - 1;
	printf("max short_u = %d\n", us);

	printf("%050d %s\n", 0, "-> int");
	t = t << 31;
	printf("min int_t = %d, ", t);
	t = t - 1;
	printf("max int_t = %d\n", t);
	u <<= 32;
	printf("min int_u = %lu, ", u);
	u -= 1;
	printf("max int_u = %lu\n", u);
	
	printf("%050d %s\n", 0, "-> long");
	tl <<= 63;
	printf("min long_t = %ld, ", tl);
	tl -= 1;
	printf("max long_t = %ld\n", tl);
	ul = (tl + 1) << 1;
	printf("min long_u = %lu, ", ul);
	ul -= 1;
	printf("max long_u = %lu\n", ul);

	
	printf("-1L < 1U : %d, -1L: %ld, 1U: %ld\n", -1L < 1U, -1L, (long) 1U); // 1U가 signed long으로 변환..
	printf("-1L > 1UL : %d, -1L: %lu, 1UL: %lu\n", -1L > 1UL, (unsigned long) -1L, 1UL);

	printf("%d\n", (1 << 31) - 1);
}
