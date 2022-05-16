#include <limits.h>
#include <stdio.h>

int main(void)
{
	char	tc = 1;
	unsigned char	tu = 1;
	short	ts = 1;
	unsigned short	us = 1;
	int		t = 1;
	unsigned long long	u = 1ULL;
	long long		tl = 1LL;
	unsigned long long	ul = 1ULL;

	tc = tc << 7;
	printf("min char_t = %d, ", tc);
	tc = tc - 1;
	printf("max char_t = %d\n", tc);
	tu = tu << 8;
	printf("min char_u = %d, ", tu);
	tu = tu - 1;
	printf("max char_u = %d\n", tu);

	printf("%050s\n", "-> short");
	ts = ts << 15;
	printf("min short_t = %d, ", ts);
	ts = ts - 1;
	printf("max short_t = %d\n", ts);
	us = us << 16;
	printf("min short_u = %d, ", us);
	us = us - 1;
	printf("max short_u = %d\n", us);

	printf("%050s\n", "-> int");
	t = t << 31;
	printf("min int_t = %d, ", t);
	t = t - 1;
	printf("max int_t = %d\n", t);
	u <<= 32;
	printf("min int_u = %u, ", u);
	u -= 1;
	printf("max int_u = %u\n", u);
	
	printf("%050s\n", "-> long");
	tl <<= 63;
	printf("min long_t = %lld, ", tl);
	tl -= 1;
	printf("max long_t = %lld\n", tl);
	ul = (tl + 1) << 1;
	printf("min long_u = %llu, ", ul);
	ul -= 1;
	printf("max long_u = %llu\n", ul);
}