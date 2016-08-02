#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[])
{
	int child, pid, status;
	pid = fork();
	if(pid == 0)
	{
		execvp(argv[1], &argv[1]);
			//문자열	문자열들의 배열(첫번쨰 문자열의 포인터)
		fprintf(stderr, "%s:failed\n", argv[1]);
	}
	else
	{
		child = wait(&status);
		printf("[%d] child process %d finished", getpid(), child);
		printf("\t exit code %d \n", status >> 8);
	}
}
