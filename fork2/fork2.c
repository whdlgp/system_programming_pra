#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int pid;

	pid = fork();

	if(pid == 0)//자식 프로세스
	{
		printf("[child] : Hello, world pid = %d \n", getpid());
	}
	else // 부모 프로세스
	{
		printf("[parent] : Hello, world pid = %d \n", getpid());
	}

	return 0;
}
