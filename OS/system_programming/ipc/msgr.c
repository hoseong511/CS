#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct msgbuf
{
	long	type;
	char	text[50];
} MsgBuf;

int	main(void)
{
	MsgBuf	msg;
	int		msgid, len;
	key_t	key = 1234;
	msgid = msgget(key, IPC_CREAT|0644);
	if (msgid == -1)
	{
		perror("msgget");
		exit(1);
	}
	msg.type = 1;
	strcpy(msg.text, "Hello Message Queue\n");
	if (msgsnd(msgid, (void *)&msg, 50, IPC_NOWAIT) == -1)
	{
		perror("msgsnd");
		exit(1);
	}
	len = msgrcv(msgid, &msg, 50, 0, 0);
	printf("Received Message is [%d] %s\n", len, msg.text);
	return (0);
}