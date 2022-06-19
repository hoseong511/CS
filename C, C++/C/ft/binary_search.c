/* binarsearch : find x in v[0] <= v[1] <= ...*/

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
int	binary_search(int x, int v[], int n)
{
	int	low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int binary_search2(int x, int v[], int n)
{
	int	low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return ((v[mid] == x) ? mid : -1);
}

double calc_diff_time(struct timeval _x, struct timeval _y) {
    double x_us, y_us, diff;

    x_us = (double)_x.tv_sec * 1000000 + (double)_x.tv_usec;
    y_us = (double)_y.tv_sec * 1000000 + (double)_y.tv_usec;

    diff = (double)y_us - (double)x_us;

    return diff;
}

int	main(void)
{
	struct timeval start, end;
	double	result;
	int		arr[6] = {-1, 0 , 1, 2, 3, 4};


	gettimeofday(&start, NULL);
	int ans = binary_search(2, arr, 6);
	sleep(1);
	gettimeofday(&end, NULL);
	printf("binary : %d %d\n", start.tv_usec, end.tv_usec);
	
	gettimeofday(&start, NULL);
	ans = binary_search2(2, arr, 6);
	gettimeofday(&end, NULL);
	printf("binary : %.01f\n", calc_diff_time(start, end));
}