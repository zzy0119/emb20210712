#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE	64

static int semid;

int childJob();
int main(void)
{
	pid_t pid;
	int i;

	semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0600);
	if (-1 == semid) {
		perror("semget()");
		exit(1);
	}

	semctl(semid, 0, SETVAL, 1);

	for (i = 0; i < 10; i++) {
		pid = fork();
		if (-1 == pid) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			childJob();	
			exit(0);
		}
	}

	for (i = 0; i < 10; i++)
		wait(NULL);

	semctl(semid, 0, IPC_RMID, NULL);
	exit(0);
}

static int P()
{
	struct sembuf buf;

	buf.sem_num = 0;
	buf.sem_op = -1;
	buf.sem_flg = 0;

	semop(semid, &buf, 1);
}

static int V()
{
	struct sembuf buf;

	buf.sem_num = 0;
	buf.sem_op = 1;
	buf.sem_flg = 0;

	semop(semid, &buf, 1);
}

int childJob()
{
	FILE *fp;
	char buf[BUFSIZE] = {};

	fp = fopen("./test.txt", "r+");

	// 竞争
	// 拿信号
	P();
	// io;
	fgets(buf, BUFSIZE, fp);
	rewind(fp);
	sleep(1);
	fprintf(fp, "%d", atoi(buf)+1);
	fclose(fp); // buf
	V();

	return 0;
}



