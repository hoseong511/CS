#include "binary_search.h"

int	binary_search(int arr[], int n, size_t length)
{
	size_t	mid, low, high, guess;

	(void)n;
	low = 0;
	high = length - 1;
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		guess  = arr[mid];
		if (guess == n)
			return mid;
		if (guess < n)
			low = mid + 1;
		else if (guess > n)
			high = mid - 1;
	}
	return -1;
}
