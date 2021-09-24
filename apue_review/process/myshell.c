#include <stdio.h>
#include <glob.h> /*glob(3)*/
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

static char **parseString(char *ptr, const char *delim);
int main(void)
{
	char *ptr = NULL;
	size_t n = 0;
	char **argv;
	pid_t pid;

	while (1) {
		printf("[myshell]$ ");	
		if (getline(&ptr, &n, stdin) == -1)// 读用户输入的一行命令
			break;
		if (!strcmp(ptr, "exit\n"))
			break;
		// "ls -l"--->"ls" "-l"(strtok())
		argv = parseString(ptr, " \n\t");
// 		pid = fork();
		pid = vfork();
		// 
		if (0 == pid) {
			execvp(argv[0], argv);
			perror("execvp()");
			exit(1);
		}
		// wait(NULL);	
	}

	exit(0);
}

// char *arr[] = {"ls", "-l", NULL};-->char **
static char **parseString(char *ptr, const char *delim)
{
	char *ret = NULL;
	// glob_t res;
	int flag = 0;
	char **argv;
	int n = 1;

	argv = calloc(n, sizeof(char *));

	while (1) {
		ret = strsep(&ptr, delim);
		if (ret == NULL)
			break;
		if (!strcmp(ret, ""))
			continue; // delim连续
	// 	glob(ret, GLOB_NOCHECK | GLOB_APPEND * flag, NULL, &res);
		// flag = 1;	
		argv = realloc(argv, (n + 1) * sizeof(char *));
		argv[n-1] = ret;
		n++;
	}	
	argv[n-1] = NULL;

	// return res.gl_pathv;
	return argv;
}

