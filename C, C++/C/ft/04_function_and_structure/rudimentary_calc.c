#include "main.h"
#define MAXLINE 100

int main(void)
{
	double sum, ho_atof(char[]);
	char line[MAXLINE];

	sum = 0;
	while (ho_getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += ho_atof(line));
	return (0);
}