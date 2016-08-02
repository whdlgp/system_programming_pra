#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	pid_t pid1, pid2;
	int status;

	pid1 = pid2 = -1;
	printf("before fork: pid1(%d), pid2(%d)\n", pid1, pid2);
	pid1 = fork();
	printf("after 'pid1' fork: pid1(%d), pid2(%d)\n", pid1, pid2);

	if(pid1 > 0)
	{
		pid2 = fork();
		printf("after 'pid2' fork: pid1(%d), pid2(%d)\n", pid1, pid2);
	}

	if(pid1 > 0 && pid2 > 0)
	{
		waitpid(pid2, &status, 0);
		printf("parent: child2 exit(%d)\n", status);
		waitpid(pid1, &status, 0);
		printf("parent: child1 exit(%d)\n", status);
		printf("after 'watipid' : pid1(%d), pid2(%d)\n", pid1, pid2);
	}
	else if(pid1 == 0 && pid2 < 0)
	{
		sleep(1);
		exit(1);
		printf("pid1(%d), pid2(%d)\n", pid1, pid2);
	}
	else if(pid1 > 0 && pid2 == 0)
	{
		sleep(2);
		exit(2);
		printf("pid1(%d), pid2(%d)\n", pid1, pid2);
	}
	else
	{
		printf("fail to fork\n");
	}

	return 0;
}
