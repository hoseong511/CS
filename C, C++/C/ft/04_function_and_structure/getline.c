#include "main.h"

int	ho_getline(char s[], int lim)
{
	int	c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != -1 && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}