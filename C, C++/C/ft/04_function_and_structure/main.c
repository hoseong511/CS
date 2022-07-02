#include "main.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("%lf\n", ho_atof(argv[1]));
	printf("%lf\n", atof(argv[1]));
	return (0);
}