#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	int shmid;	
	pid_t pid;
	char *ptr;

	shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | IPC_EXCL | 0600);
	if (-1 == shmid) {
		if (EEXIST == errno) {
			shmid = shmget(IPC_PRIVATE, 1024, 0);
		} else {
			perror("shmget()");
			exit(1);
		}
	}

	pid = fork();	
	if (-1 == pid) {
		perror("fork()");
		goto ERROR;
	}
	if (0 == pid) {
		ptr = shmat(shmid, NULL,  0);
		memcpy(ptr, "good afternoon", 14);
		shmdt(ptr);
		exit(0);
	}
	wait(NULL);

	ptr = shmat(shmid, NULL, 0);
	sleep(20);
	puts(ptr);
	shmdt(ptr);

	shmctl(shmid, IPC_RMID, NULL);

	return 0;
ERROR:
	shmctl(shmid, IPC_RMID, NULL);
	exit(1);
}


