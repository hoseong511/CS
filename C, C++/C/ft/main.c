#include "ft.h"

int main(void)
{
	char	*a = ft_strdup("1234563837393037123124124124123123");
	char	*b = ft_strdup("123456789");
	ft_squeeze(a, '3');
	printf("%s\n", a);
	free(a);
	int c = ft_any(b, "397");
	(void) c;
	ft_ssqueeze(b, "345");
}
