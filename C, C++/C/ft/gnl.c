#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
char	*pre_gnl(int fd, int len, char *res)
{
	char	buf = 0;
	char	byte;

	byte = read(fd, &buf, 1);
	if (byte == 0 || buf == '\n')
	{
		res = (char *)malloc(sizeof(char) * (len + 1));
		res[len + 1] = '\0';
	}
	else
		res = pre_gnl(fd, len + 1, res);
	if (res)
		res[len] = buf;
	return (res);
}

char	*gnl(int fd)
{
	char	*res;

	res = NULL;
	res = pre_gnl(fd, 1, res);
	return (res);
}

int	main(void)
{
	char	*line;

	int fd = open("hihi", O_RDONLY);
	line = gnl(fd);
	printf("%s", line);
}
