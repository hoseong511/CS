#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

/* shellsort : sort v[0] ... v[n-1]*/
void	shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
			for (j = i-gap; j >= 0 && v[j]>v[j+gap]; j-=gap)
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
	}
}

int	main(void)
{
	int *arr;
	int	tmp;

	arr = ft_calloc(10, sizeof(int));
	if (!arr)
		return (0);
	int n = -1;
	while (++n < 10)
	{
		tmp = rand() % 10;
		int i = 0;
		while (i < n)
		{
			if (arr[i] == tmp)
			{
				n--;
				break;
			}
			i++;
		}
		if (n == i)
			arr[n] = tmp;
	}
	while (n-- > 0)
		printf("%d%c", arr[n], n == 0 ? '\n' : ' ');
	
	shellsort(arr, 10);

	n = -1;
	while (++n < 10)
		printf("%d ", arr[n]);

}
