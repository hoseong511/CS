#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAXLINE 64

int	main(int argc, char **argv)
{
	char	buf[MAXLINE];
	pid_t	pid;

	printf("miniShell ver 1.1\n");
	while(1)
	{
		memset(buf, 0x00, MAXLINE);
		fgets(buf, MAXLINE - 1, stdin);
		// char *fgets (char *string, int n, FILE *stream)
		if (strncmp(buf, "exit\n", 5) == 0)
			break;
		buf[strlen(buf) - 1] = 0x00; // 입력된 엔터 값을 0x00으로
		pid = fork();
		if (pid == 0)
		{
			if (execlp(buf, buf, NULL) == -1)
			{
				printf("command execution is failed\n");
				exit(0);
			}
		}
		if (pid > 0)
			wait(NULL);
	}
	return (0);
}