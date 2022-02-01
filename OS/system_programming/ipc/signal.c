/* 
	시그널 핸들러
	시그널 재정의
*/
#include <signal.h>
#include <stdlib.h>

static void signal_handler (int signo)
{
	printf("Catch SIGINT!\n");
	exit(EXIT_SUCCESS);
}

int main(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
	{
		printf("Can't catch SIGINT!\n");
		exit(EXIT_FAILURE);
	}
	for (;;)
		pause();
	return (0);
}