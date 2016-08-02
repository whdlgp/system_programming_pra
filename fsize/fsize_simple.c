#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	char buffer[512];
	int fd;
	ssize_t nread;

	if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
	}
	else
	{
		nread = read(fd, buffer, 512);
	}

	close(fd);

	printf("%s file size : %ld byte\n", argv[1], (long int)nread);
	exit(0);

	return 0;
}
