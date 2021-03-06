#include <stdio.h>
#define MAXLINE 1000

void	copy(char to[], char from[]);
int		getline_2(char s[], int max);


int	main(void)
{
	int	len;
	char	line[MAXLINE];

	while ((len = getline_2(line, MAXLINE)) > 0)
		printf("%s", line);
	return (0);
}

int	getline_2(char s[], int lim)
{
	int	c, i;

	for (i=0; i < lim - 1 && (c=getchar()) != EOF && c!= '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return (i);
}

void	copy(char to[], char from[])
{
	int	i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
