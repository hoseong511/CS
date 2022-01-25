#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	printf("excute ls\n");
	execl("/bin/ls", "ls", "-al", NULL);
	perror("execl is failed\n");
	exit(1);
}