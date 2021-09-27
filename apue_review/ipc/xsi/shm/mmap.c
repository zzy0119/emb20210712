#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>

int main(void)
{
	pid_t pid;
	char *ptr;

	ptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, \
			MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	pid = fork();	
	if (-1 == pid) {
		perror("fork()");
		goto ERROR;
	}
	if (0 == pid) {
		memcpy(ptr, "good afternoon", 14);
		munmap(ptr, 1024);
		exit(0);
	}
	wait(NULL);
	puts(ptr);

	munmap(ptr, 1024);

	return 0;
ERROR:
	exit(1);
}


