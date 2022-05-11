#include "binary_search.h"

int	main(void)
{
	int arr[] = {1,2,3,4,5,6};
	printf("idx : %d\n",binary_search(arr, 5, sizeof(arr) / sizeof(arr[0])));
}