#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(symlink(argv[1], argv[2]) == -1)
	{		//원래파일	링크걸 이름
		exit(1);
	}
	exit(0);
}
