#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	printf("pid=%d\n", getpid());
	printf("ppid=%d\n", getppid());

	while (1)
	;
	return (0);
}
