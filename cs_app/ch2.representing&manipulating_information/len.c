int	intlen(int arr[])
{
	int len, target;

	len = 0;
	while ((target = arr[len]))
		++len;
	return len;
}