/* bitcount: count 1 bits in x */

int	bitcount(unsigned x)
{
	int	count;

	count = 0;
	while (x != 0)
	{
		if (x & 01)
			count++;
		x >>= 1;
	}
	return (count);
}

int	bitcount2(unsigned x)
{
	int	count;

	count = 0;
	while (x != 0)
	{
		count++;
		x &= (x - 1);
	}
	return (count);
}

int	main(void)
{
	int a = bitcount(0xffffffff);
	int b = bitcount2(0xffffffff);
}