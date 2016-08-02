#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	char *originalName = "manage.txt";
	char *hardfileName = "manage.txt.hard";
	char *softfileName = "manage.txt.soft";

	int fd, retval;
	mode_t oldmask;
	char buffer[1024];
	int nread;
	struct stat fileinfo;

	oldmask = umask(0377); //011 111 111

	fd = open(originalName, O_CREAT, 0755); //111 101 101
	close(fd);

	if ((retval = access(originalName, W_OK)) == -1)
	{
		printf("%s is not writable \n", originalName);
		chmod(originalName, 0644);
	}

	printf("%d\n", retval);

	link(originalName, hardfileName);
	symlink(originalName, softfileName);
	rename(hardfileName, "manage.hard.new");

	nread = readlink(softfileName, buffer, 1024);
	write(1, buffer, nread);

	stat(originalName, &fileinfo);
	printf("\n%s\n",originalName);
	printf("File mode : %o\n", fileinfo.st_mode);
	printf("File Size : %ld bytes\n", fileinfo.st_size);
	printf("Number of Blocks : %ld\n", fileinfo.st_blocks);

	return 0;
}
