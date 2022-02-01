#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# define MSGSIZE 20


char	*msg = "hello child process!";
int	main()
{
	char	buf[255];
	int		fd[2], pid, nbytes;
	if (pipe(fd) < 0)
		exit(1);
	pid = fork();
	if (pid > 0)
	{
		write(fd[1], msg, MSGSIZE);
		exit(0);
	}
	else
	{
		nbytes = read(fd[0], buf, MSGSIZE);
		printf("%d %s\n", nbytes, buf);
		exit(0);
	}
	return (0);
}
