
int main(void)
{
	while (1) {
		printf("[myshell]$ ");	
		getline();// 读用户输入的一行命令
		// "ls -l"--->"ls" "-l"(strtok())
		pid = fork();
		// 
		if (0 == pid) {
			execvp();
		}
		wait(NULL);	
	}

	exit(0);
}

