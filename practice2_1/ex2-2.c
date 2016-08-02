#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	mode_t oldmask;

	oldmask = umask(033);
	fd = open("fd.txt", O_CREAT, 0777);
	close(fd);
	return 0;
}
