#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main(void)
{
	int	pid;
	int	child_pid;
	int	status;
	pid = fork();
	switch (pid)
	{
		case -1:
			perror("fork is failed\n");
			break;
		case 0:
			execl("/bin/ls", "ls", "-al", NULL);
			perror("execl is failed\n");
			break;
		default:
			child_pid = wait(&status);
			printf("Parent process id : %d, Child process id : %d\n", getpid(), child_pid);
			if (WIFEXITED(status))
				printf("child process is normally terminated\n");
			exit(0);
	}
}