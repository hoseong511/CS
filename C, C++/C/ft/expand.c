#include <stdlib.h>
#include "libft/libft.h"


void	expand(char *s1, char *s2)
{
	int i, j, tmp;

	i = j = 0;
	while (s1[i])
	{
		if (s1[i] == '-' && s1[i + 1] &&
			((ft_isdigit(s1[i - 1]) && ft_isdigit(s1[i + 1])) ||
			(ft_isalpha(s1[i - 1]) && ft_isalpha(s1[i + 1]))))
		{
			tmp = s1[i - 1] + 1;
			while (tmp <= s1[i + 1])
				s2[j++] = tmp++;
			i += 2;
		}
		else if (s1[i] == '-')
			i++;
		else
			s2[j++] = s1[i++];
	}
	s2[j] = '\0';
}

int	main(int argc, char **argv)
{
	char *s1 = argv[1];
	char s2[1024];

	if (argc != 2)
		return (0);
	expand(s1, s2);
	ft_putendl_fd(s2, 1);
}