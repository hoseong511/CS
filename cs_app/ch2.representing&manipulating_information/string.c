#include "show_byte.h"

int	main(void)
{
	const char	*m = "mnopqr";
	show_bytes((byte_pointer) m, 6);

	return (0);
}