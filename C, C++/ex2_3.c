#include <ctype.h>
#include <string.h>
#include <stdio.h>

enum e_hex {A = 10, B = 11, C = 12, D = 13, E = 14, F = 15};


int	htoi(char *s)
{
	int	i, n, c;
	n = 0;

	for (i = 0; i < strlen(s); i++)
	{
		if (tolower(s[i]) == 'x' || (i == 0 && s[i] == '0'))
			continue;
		c = s[i];
		if (isdigit(c))
			n = 16 * n + (c -'0');
		else
		{
			switch (tolower(c))
			{
			case 'a':
				c = A;
				break;
			case 'b':
				c = B;
				break;
			case 'c':
				c = C;
				break;
			case 'd':
				c = D;
				break;
			case 'e':
				c = E;
				break;
			case 'f':
				c = F;
				break;
			default:
				break;
			}
			n = 16 * n + c;
		}
	}
	return (n);
}

int	main(void)
{
	printf("htoi(%s) : %d\n","0x41", htoi("0x41"));
	printf("htoi(%s) : %d\n","0x63", htoi("0x63"));
	printf("htoi(%s) : %d\n","0x7f", htoi("0x7f"));
	printf("htoi(%s) : %d\n","0xAB", htoi("0xAB"));
	printf("htoi(%s) : %d\n","0xABC", htoi("0xABC"));
}