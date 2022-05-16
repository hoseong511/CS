#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# define MSGSIZE 255


char	*msg = "hello child process!";
int	main()
{
	char	buf[255];
	int		fd[2], pid, nbytes;
	if (pipe(fd) < 0)
		exit(1);
	pid = fork(); // fork 후 자식 프로세스 pid가 return 된다.
	if (pid > 0)
	{
		printf("parent PID : %d, child PID : %d\n", getpid(), pid);
		write(fd[1], msg, MSGSIZE);
		exit(0);
	}
	else
	{
		printf("child PID: %d\n", getpid());
		nbytes = read(fd[0], buf, MSGSIZE);
		printf("%d %s\n", nbytes, buf);
		exit(0);
	}
	return (0);
}
