#include "main.h"

void	itoa_field(int n, char s[], int f)
{
	int i, sign;

	sign = n;
	i = 0;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10));
	if (sign < 0)
		s[i++] = '-';
	while (i < f)
		s[i++] = sign < 0 ? ' ' : '0';
	s[i] = '\0';
	while (i-- > 0)
		printf("%c%c", s[i], i == 0 ? '\n' : 0);
}

int main(int argc, char const *argv[])
{
	char s[1024];

	(void) argc;
	if (argc != 3)
		return (0);
	itoa_field(atoi(argv[1]), s, atoi(argv[2]));
	return 0;
}