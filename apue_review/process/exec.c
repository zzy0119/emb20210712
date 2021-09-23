#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	// if error

	if (0 == pid) {
		// execl("/bin/ls", "ls", "-l", NULL);
		char *arr[] = {"ls", "-l", NULL};
		// execv("/bin/ls", arr);
		execvp("ls", arr);
		perror("execl()");
		exit(1);
	}
	wait(NULL);
	printf("the calling process will be end\n");

	exit(0);
}

