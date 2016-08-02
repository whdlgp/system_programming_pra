#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	char buffer[512];
	int fd;
	ssize_t nread;
	long total = 0;

	if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
	}

	while((nread = read(fd, buffer, 512)) > 0)
	{
		total += nread;
	}

	close(fd);

	printf("%s file size : %ld byte\n", argv[1], total);
	exit(0);

	return 0;
}
