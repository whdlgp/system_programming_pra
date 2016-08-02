#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int pid1, pid2;
	
	pid1 = fork();

	if(pid1 == 0)
	{
		printf("[child 1] Hello, world! pid = %d\n", getpid());
		exit(0);
	}

	pid2 = fork();
	
	if(pid2 == 0)
	{
		printf("[child 2] Hello, world! pid = %d\n", getpid());
		exit(0);
	}

	return 0;
}
