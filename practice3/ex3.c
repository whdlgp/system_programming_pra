#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>


int main(void)
{
	char buffer[256];
	DIR *dirp;
	struct dirent *dentry;

	getcwd(buffer, 256);
	printf("%s\n", buffer);

	mkdir("apple", 0755);
	mkdir("banana", 0755);
	chdir("apple");
	getcwd(buffer, 256);
	printf("%s\n", buffer);

	close(open("data1.txt", O_CREAT | O_RDWR, 0644));
	close(open("data2.txt", O_CREAT | O_RDWR, 0644));

	chdir("..");
	rmdir("apple");
	rmdir("banana");

	dirp = opendir("apple");
	while(dentry = readdir(dirp))
		printf("%s\n", dentry -> d_name);
	rewinddir(dirp);
	printf("[rewind directory]\n");
	if(dentry = readdir(dirp))
		printf("%s\n", dentry -> d_name);
	closedir(dirp);

	return 0;
}
