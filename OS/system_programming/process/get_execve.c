#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*envp[] = {"USER=HOHO", NULL};
	char	*arg[] = {"ls", "-al", NULL};

	printf("excute ls!\n");
	execve("/bin/ls", arg, envp); // PATH가 초기화 되므로 실행 파일 경로 필요
	perror("execve is failed\n");
	exit(1);
}
