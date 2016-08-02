#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("parent process start\n");
	
	if(fork() == 0)
	{
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "first fail");
		sleep(1);
		exit(1);
	}

	if(fork() == 0)
	{
		execl("/bin/date", "date", NULL);
		fprintf(stderr, "second fail");
		sleep(2);
		exit(2);
	}

	if(fork() == 0)
	{
		execl("/bin/ls", "ls", "-l", NULL);
		fprintf(stderr, "third fail");
		sleep(3);
		exit(3);
	}

	sleep(6);

	printf("parent process finish\n");

	return 0;
}
