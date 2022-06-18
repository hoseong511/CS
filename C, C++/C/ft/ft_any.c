
#include "ft.h"

int	ft_any(char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s1[++i] != '\0')
	{
		if (ft_strchr(s2, s1[i]))
			return (i);
		else
			s1[j++] = s1[i];
	}
	return (-1);
}