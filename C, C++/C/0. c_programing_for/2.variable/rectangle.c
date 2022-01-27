#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int	main(int argc, char *argv[])
{
	int	width, height;
	int area, perimeter;

	if (argc < 3)
	{
		printf("Check arguments!\n");
		return (0);
	}
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	perimeter = 2 * (width + height);
	area = width * height ;
	printf("perimeter : %d\n", perimeter);
	printf("area : %d\n", area);
	return (0);
}