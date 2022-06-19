#include <stdio.h>

char	to_lower(char c)
{
	char	res;
	res = ('A' <= c && c <= 'Z') || ('a' <=c && c <= 'z');
	return (res ? c | 0x20 : c);
}

char	to_upper(char c)
{
	char	res;
	res = ('A' <= c && c <= 'Z') || ('a' <=c && c <= 'z');
	return (res ? c & ~0x20 : c);
}

int	main(void)
{
	printf("%c %c %c\n", to_lower('A'), to_lower('a'), to_lower('1'));
	printf("%c %c %c\n", to_upper('a'), to_upper('A'), to_upper('1'));
}