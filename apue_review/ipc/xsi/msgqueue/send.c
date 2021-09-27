#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "proto.h"

int msgInit(void);
int main(int argc, char *argv[])
{
	int msgid;	
	struct msg_st sndbuf;

	if (argc < 4)
		exit(1);

	msgid = msgInit();
	if (msgid < 0) {
		fprintf(stderr, "msgInit():%s\n", strerror(-msgid));
		exit(1);
	}


	sndbuf.stu.id = atoi(argv[1]);
	strncpy(sndbuf.stu.name, argv[2], NAMESIZE);
	sndbuf.mtype = atoi(argv[3]);
	msgsnd(msgid, &sndbuf, sizeof(struct stu_st), 0);

	exit(0);
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





