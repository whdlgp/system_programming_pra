#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void cleanUpAction(void);

int main(void)
{
	pid_t pid;
	int i;
	char *arg[] = {"ls", "-l", "/home/mongcom/desktop/test/practice4", NULL};

	for(i = 0; i < 3; i++)
	{
		printf("befor fork [%d]\n", i);
		sleep(1);
	}
	pid = fork();

	if(pid > 0)
	{
		for(; i < 7; i++)
		{
			printf("parent [%d]\n", i);
			sleep(1);
		}
		atexit(cleanUpAction);
	}

	else if(pid == 0)
	{
		for(; i < 5; i++)
		{
			printf("child[%d]\n", i);
			sleep(1);
			execv("/bin/ls", arg);
		}
	}

	else
	{
		{
			printf("fail to fork child process\n");
		}
	}
	exit(0);
	return 0;
}

void cleanUpAction(void)
{
	printf("cleanUpAction!\n");
}
