#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	if((pid = fork()) > 0)
	{
		sleep(1);
		exit(1);
	}
	else if(pid == 0)
	{
		printf("old session id : %d\n", getsid(0));
		printf("new session id : %d\n", setsid());
		sleep(600);
	}

	return 0;
}
