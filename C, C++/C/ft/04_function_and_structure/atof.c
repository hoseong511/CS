#include <ctype.h>

double	ho_atof(char s[])
{
	double val, power;
	int	i, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return (sign * val / power);
}

double	ft_atof(char *s)
{
	double	val;
	double	power;
	int		i;
	int		sign;

	i = 0;
	while (isspace(s[i]))
		i++;
	sign = 1;
	if (s[i++] == '-')
		sign = -1;
	val = 0.0;
	while (isdigit(s[i]))
		val = 10.0 * val + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	power = 1.0;
	while (isdigit(s[i]))
	{
		val = 10.0 * val + (s[i++] - '0');
		power *= 10.0;
	}
	return (sign * val / power);
}