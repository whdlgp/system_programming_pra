#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	pid_t pid;
	int interval;

	pid = atoi(argv[1]);
	interval = atoi(argv[2]);

	printf("shell process... \n");
	printf("process id : %d, group id : %d, session id : %d\n", pid, getpgid(pid), getsid(pid));
																	//pid의 그룹id, pid의 세션id
	printf("current process.. not daemon... \n");
	printf("process id : %d, group id : %d, session id : %d\n", getpid(), getpgrp(), getsid(0));
																//자신pid 자신gid	자신sid
	sleep(interval);
	
	return 0;	
}

