#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#include "proto.h"
#include "share.h"

int main(int argc, char *argv[])
{
	int myshm, msgid;
	char *ptr;
	int fd;
	struct server_st rcv;
	int cnt;

	if (argc < 2)
		exit(1);

	myshm = shmInit();	
	if (myshm < 0) {
		fprintf(stderr, "shmInit():%s\n", strerror(-myshm));
		exit(0);
	}

	ptr = shmat(myshm, NULL, 0);
	strcpy(ptr, argv[1]);

	shmdt(ptr);
	
	msgid = msgInit();	
	if (msgid < 0) {
		fprintf(stderr, "msgInit():%s\n", strerror(-msgid));
		goto ERROR_MSG;
	}

	while (1) {
		cnt = msgrcv(msgid, &rcv, TEXTSIZE, 0, 0);
		if (-1 == cnt) {
			perror("msgrcv");
			goto ERROR_READ;
		}
		if (!strcmp(rcv.mtext, "end"))
			break;
		write(1, rcv.mtext, cnt);
	}

	msgctl(msgid, IPC_RMID, NULL);

	exit(0);
ERROR_SHM:
ERROR_READ:
	close(fd);
ERROR_OPEN:
	msgctl(msgid, IPC_RMID, NULL);
ERROR_MSG:
	shmctl(myshm, IPC_RMID, NULL);
	exit(1);
}



