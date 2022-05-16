#include <stdio.h>

int	main(void)
{
	enum Company
	{
		Google,
		Yahoo,
		Facebook,
		Xerox,
		Ebay,
		Microsoft
	};
	enum Company xerox = Xerox;
	enum Company google = Google;
	enum Company ebay = Ebay;

	printf("Company is %d\n", xerox);
	printf("Company is %d\n", ebay);
	printf("Company is %d\n", google);

	return (0);
}