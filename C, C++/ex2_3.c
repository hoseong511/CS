#include <ctype.h>
#include <string.h>
#include <stdio.h>

enum e_hex {A = 10, B = 11, C = 12, D = 13, E = 14, F = 15};


int	htoi(char *s)
{
	int	i, n;
	char c;
	n = 0;

	for (i = strlen(s); i >= 0; i--)
	{
		c = s[i-1];
		if (tolower(s[1]) != 'x' && s[0] != '0')
			break;
		switch (c)
		{
		case 'a':
			c = A;
		case 'b':
			c = B;
		case 'c':
			c = C;
		case 'd':
			c = D;
		case 'e':
			c = E;
		case 'f':
			c = F;
		default:
			n = 16 * n + (c - '0');
			break;
		}
	}
	return (n);
}

int	main(void)
{
	printf("htoi() : %d\n", htoi("0x41"));
}