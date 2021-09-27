#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "proto.h"

int msgInit(void);
int main(void)
{
	int msgid;	
	struct msg_st rcvbuf;

	msgid = msgInit();
	if (msgid < 0) {
		fprintf(stderr, "msgInit():%s\n", strerror(-msgid));
		exit(1);
	}

	while (1) {
		if (msgrcv(msgid, &rcvbuf, sizeof(struct stu_st), 0, 0) == -1) {
			perror("msgrcv()");
			goto ERROR;
		}
		printf("%d %s\n", rcvbuf.stu.id, rcvbuf.stu.name);
	}

	exit(0);
ERROR:
	msgctl(msgid, IPC_RMID, NULL);
	exit(1);
}

int msgInit(void)
{
	key_t key;
	int msgid;

	key = ftok(PATHNAME, PROJID);
	if (-1 == key)
		return -errno;

	msgid = msgget(key, IPC_CREAT | IPC_EXCL |0600);
	if (-1 == msgid) {
		if (EEXIST == errno) {
			msgid = msgget(key, 0);
		} else
			return -errno;
	}

	return msgid;
}





