#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i;
	struct stat buf;

	for(i = 1; i < argc; i++)
	{
		printf("%s :", argv[i]);
		if(lstat(argv[i], &buf) < 0)
		{
			perror("lstat()");
			continue;
		}

		if(S_ISREG(buf.st_mode))
		{
			printf("%s \n", "Regular file");
		}
		if(S_ISDIR(buf.st_mode))
		{
			printf("%s \n", "Directory file");
		}	
		if(S_ISCHR(buf.st_mode))
		{
			printf("%s \n", "Character device file");
		}
		if(S_ISBLK(buf.st_mode))
		{
			printf("%s \n", "Block device file");
		}
		if(S_ISLNK(buf.st_mode))
		{
			printf("%s \n", "Symbolic file");
		}
	}

	exit(0);
	return 0;
}
