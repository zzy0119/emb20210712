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
	struct server_st snd;
	int cnt;

	myshm = shmInit();	
	if (myshm < 0) {
		fprintf(stderr, "shmInit():%s\n", strerror(-myshm));
		exit(0);
	}
	ptr = shmat(myshm, NULL, 0);
	while (1) {
		if (strcmp(ptr, "")) {
			break;
		}
	}
	
	msgid = msgInit();	
	if (msgid < 0) {
		fprintf(stderr, "msgInit():%s\n", strerror(-msgid));
		goto ERROR_MSG;
	}

	fd = open(ptr, O_RDONLY);
	if (-1 == fd) {
		perror("open()");	
		goto ERROR_OPEN;
	}

	shmdt(ptr);

	snd.mtype = 1;
	while (1) {
		memset(snd.mtext, '\0', TEXTSIZE);
		cnt = read(fd, snd.mtext, TEXTSIZE);	
		if (-1 == fd) {
			perror("read()");
			goto ERROR_READ;	
		}
		if (cnt == 0) {
			strcpy(snd.mtext, "end");
			msgsnd(msgid, &snd, 4, 0);
			break;
		}
		msgsnd(msgid, &snd, cnt, 0);
	}

	shmctl(myshm, IPC_RMID, NULL);

	exit(0);
ERROR_SHM:
ERROR_MSG:
	shmctl(myshm, IPC_RMID, NULL);
ERROR_OPEN:
	msgctl(msgid, IPC_RMID, NULL);
ERROR_READ:
	close(fd);
	exit(1);
}



