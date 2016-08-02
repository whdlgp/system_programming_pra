#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("parent process start\n");

	if(fork() == 0)
	{
		execl("/bin/echo", "echo", "hello", NULL); //echo라는 외부 프로그램 실행
				//경로		명령	값		마지막NULL
		fprintf(stderr, "failed");
		exit(1);
	}
	
	sleep(1); //부모자식 끝나는 순서 맞추려고
	printf("parent process exit\n");
	return 0;
}
