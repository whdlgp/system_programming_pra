#include <stdio.h>

int main(void)
{
	int pid;
	printf("[%d] process start \n", getpid());

	pid = fork();
	printf("[%d] process : return value %d \n", getpid(), pid);

	return 0;
}
