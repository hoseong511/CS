#include "main.h"

void	itob(int n, char s[], int b)
{
	int i, sign;
	char hex[16] = "0123456789abcdef";

	sign = n;
	i = 0;
	do
	{
		s[i++] = hex[abs(n) % b];
	} while ((n /= b));
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	while (i-- > 0)
		printf("%c%c", s[i], i == 0 ? '\n' : 0);
}

int main(int argc, char *argv[])
{
	char s[1024];

	if (argc != 3)
		return (0);
	itob(atoi(argv[1]), s, atoi(argv[2]));
}