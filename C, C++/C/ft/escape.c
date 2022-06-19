#include "libft/libft.h"
#include <stdio.h>

char	*escape(char *str)
{
	char	*dest;
	int		len;
	int		i, j;

	len = ft_strlen(str);
	i = -1;
	while (str[++i])
	{
		switch (str[i])
		{
			case '\n':
			case '\t':
				len++;
			default:
				continue;
		}
	}
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	j = 0;
	while (++i < len)
	{
		switch (str[i])
		{
			case '\n':
				dest[j++] = '\\';
				dest[j++] = 'n';
				continue;
			case '\t':
				dest[j++] = '\\';
				dest[j++] = 't';
				continue;
			default:
				dest[j++] = str[i];
				continue;
		}
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char str[100];

	scanf("%s", str);
	char *str1 = escape(str);
	printf("str1 : %s\n", str1);
}