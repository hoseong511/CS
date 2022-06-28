#include "main.h"

void	itoa(int num, char s[])
{
	int i, sign, flag;

	flag = 0;
	if ((sign = num) < 0)
	{
		num = -num;
		if (sign == num)
		{
			num = -(num + 1);
			flag = 1;
		}
	}
	i = 0;
	do
	{
		s[i++] = num % 10 + '0';
	} while ((num /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	if (flag)
		s[0] += 1;
	while (i-- > 0)
		printf("%c%c", s[i], i == 0 ? '\n' : 0);
}

int main(int argc, char *argv[])
{
	char s[1024];

	(void) argc;
	printf("atoi(argv[1]) : %d \n", atoi(argv[1]));
	itoa(atoi(argv[1]), s);
}