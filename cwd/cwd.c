#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 256

void printcwd()
{
	char buffer[BUF_SIZE];

	if(getcwd(buffer, BUF_SIZE) == NULL) //작업하고있는 디렉토리를 버퍼에 저장하는 함수
	{
		exit(1);
	}

	printf("%s\n", buffer);
}

int main(void)
{
	printcwd();

	chdir("/usr/include"); //작업할 디렉토리 바꾸기
	printcwd();

	chdir("..");
	printcwd();
}
