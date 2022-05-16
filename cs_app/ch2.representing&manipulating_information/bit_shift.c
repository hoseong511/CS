#include "show_byte.h"

int	main(void)
{
	int		a = 2607352;
	float	b = 3510593.0;

	show_int(a);
	show_float((float) a);
	printf("%f\n", (float) a);
	show_float(b);
}