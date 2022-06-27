#include <stdlib.h>
#include "libft/libft.h"


char	*expand(char *s1)
{
	int i, start, end, len;
	char	*s2;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '-')

		i++;
	}
	if (ft_strchr(s1, '-'))
	{
		i = 0;
		while (1)
		{
			if (i == 0 && ft_isalnum(s1[i]))
				start = s1[i];
			if (s1[i - 1] == '-')
			{
				end = s1[i];
				break;
			}
			i++;
		}
		len = end - start;
		s2 = malloc(sizeof(char) * (len + 1));
		if (!s2)
			return (NULL);
		i = 0;
		while (i < len + 1)
		{
			if (i == 0)
				s2[i] = start;
			else
				s2[i] = s2[i - 1] + 1;
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	else
		return (s1);
}

int	main(int argc, char **argv)
{
	char *s1 = argv[1];
	char *s2;

	if (argc != 2)
		return (0);
	s2 = expand(s1);
	ft_putendl_fd(s2, 1);
}