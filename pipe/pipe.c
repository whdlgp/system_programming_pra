#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>


#define BUFSIZE 8192

int main() 
{
	char inbuf[BUFSIZE];
	int p[2], j, pid;

	/* open pipe */
	if(pipe(p) == -1) 
	{
		perror("pipe call error");
		exit(1);
	}

	switch(pid = fork())
	{
	case -1: perror("error: fork failed"); 
		exit(2);
	case 0: /* if child then write down pipe */
		close(p[0]); /* first close the read end of the pipe */
		write(p[1], "Hello there.", 12);
		write(p[1], "This is a message.", 18);
		write(p[1], "How are you?", 12);
		break;
	default: /* parent reads pipe */
		close(p[1]); /* first close the write end of the pipe */
		read(p[0], inbuf, BUFSIZE); /* What is wrong here?? */
		printf("Parent read: %s\n", inbuf);
		wait(NULL);
	}

	exit(0);
}
