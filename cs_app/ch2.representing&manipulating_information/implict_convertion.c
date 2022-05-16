#include <string.h>
#include <stdio.h>

float	sum_elements(float a[], int length)
{
	int	i;
	float	result = 0;

	for (i = 0; i <= length - 1; i++)
		result += a[i];
	return result;
}

int	strlonger(char *s, char *t)
{
	return (strlen(s) > strlen(t));
}

int	main(void)
{
	float a[3] = {1.0, 2.0, 3.0};
	sum_elements(a, 0);

	int result = strlonger("123", "1234");
	printf("%d", result);
}