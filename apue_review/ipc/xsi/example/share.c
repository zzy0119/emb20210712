#include <sys/ipc.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/msg.h>
#include "proto.h"
#include "share.h"

int shmInit(void)
{
	key_t key;

	key = ftok(PATH, PROJ_ID);

	int shmid = shmget(key, PATHSIZE, IPC_CREAT | IPC_EXCL | 0600);	
	if (-1 == shmid) {
		if (errno == EEXIST) {
			shmid = shmget(key, PATHSIZE, 0);
		} else {
			return -errno;
		}
	}
	return shmid;
}

int msgInit(void)
{
	int msgid;
	key_t key;

	key = ftok(PATH, PROJ_ID);

	msgid = msgget(key, IPC_CREAT | IPC_EXCL |0600);
	if (-1 == msgid) {
		if (EEXIST == errno) {
			msgid = msgget(key, 0);
		} else
			return -errno;
	}

	return msgid;


}
