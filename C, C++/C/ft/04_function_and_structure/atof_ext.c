#include <ctype.h>

double	ho_atof_ext(char s[])
{
	double val, power, point;
	int	i, sign, j;

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
	if (s[i] == 'E' || s[i] == 'e')
		i++;
	if (s[i++] == '+')
		point = 0.1;
	else
		point = 10.0;
	j = s[i] - '0';
	while (j-- > 0)
		power *= point;
	return (sign * val / power);
}