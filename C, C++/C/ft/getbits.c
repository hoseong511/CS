
unsigned	getbits(unsigned x, int p, int n)
{

	int b = ~(~0 << n);
	int c1 = (1 << n);
	int c2 = ~(1 << n);
	return (x >> (p + 1 - n)) & b;
}

/* ex: 
		x = 0b110101
		p = 4
		n = 3
		y = 0b100100

	4~2 bit		=> a = 0b10000 
	5th bit		=> b = 0b100000
	1st bit		=> c = 0b01
*/

unsigned	setbits(unsigned x, int p, int n, unsigned y)
{
	int	a = (y & ~(~0 << n)) << (p + 1 - n);
	int	b = x & (~0 << (p + 1));
	int	c = x & ~(~0 << (p + 1 - n));
	return (a | b | c);
}

unsigned	invert(unsigned x, int p, int n)
{
	int	a1 = (~getbits(x, p, n)) & ~(~0 << n);
	int	a2 = a1 << (p + 1 - n);
	int	b = x & (~0 << (p + 1));
	int	c = x & ~(~0 << (p + 1 - n));
	return (a2 | b | c);
}

unsigned	rightrot(int x, int n)
{
	int	end = 0;

	end = ~end << n;
	end = (x & ~end) << (8 * sizeof(x) - n);
	return ((x >> n) | end);
}

int	main(void)
{
	unsigned a = getbits(0b100000111011, 6, 3);
	(void) a;
	unsigned b = setbits(0b111101, 4, 3, 0b100001);
	unsigned c = setbits(0b111101, 4, 3, 0b100101);
	c = invert(0b110101, 4, 3);
}