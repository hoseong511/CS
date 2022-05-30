long	mult2(long x, long y) { return x * y;}

void	multstore(long x, long y, long *dest)
{
	long	t = mult2(x, y);
	*dest = t;
}

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	return 0;
}
