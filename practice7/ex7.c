#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(void)
{
	pid_t pid;
	int status;

	pid = fork();
	putenv("APPLE=RED");
	//HOEM, SHELL, PWD : 내장환경변수, 사용자(지정) 환경변수

	if(pid > 0)
	{
		printf("[parent] PID : %d\n", getpid());
		printf("[parent] PPID : %d\n", getppid());
		printf("[parent] GID : %d\n", getpgrp());
		printf("[parent] SID : %d\n", getsid(0));
		waitpid(pid, &status, 0);
		printf("[parent] status is %d\n", status);
		unsetenv("APPLE");
	}

	else if(pid == 0)
	{
		printf("[child] PID : %d\n", getpid());
		printf("[child] PPID : %d\n", getppid());
		printf("[child] GID : %d\n", getpgrp());
		printf("[child] SID : %d\n", getsid(0));
		sleep(1);
		printf("[child] APPLE : %s\n", getenv("APPLE"));
		exit(1);
	}
	
	else
	{
		printf("fail to fork!\n");
	}
	return 0;
}
