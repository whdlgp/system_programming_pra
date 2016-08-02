#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fd;

	if((fd = open(argv[1], O_RDWR)) == -1)
	{			//파일이름	접근범위
		perror(argv[1]);
	}
	else
	{
		printf("file %s open success\n", argv[1]);
	}
	close(fd);
	exit(0);

	return 0;
}
