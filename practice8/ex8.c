#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

void *thread(void* data);

int main(void)
{
	pthread_t threads[5];
	int rc, t;

	for(t = 0; t < 5; t++)
	{
		printf("In main: creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, thread, (void*)&t);
		sleep(1); //쓰래드쪽에서 인자를 받을 시간을 충분히 주기
		
		if(rc) //에러처리
		{
			printf("Thread creation error!\n");
			exit(1);
		}
	}

	pthread_exit(NULL);
	
	return 0;
}

void *thread(void* data)
{
	int id = *(int*)data;
	sleep(id);
	static int cnt = 0;
	//printf("Hello I'm thread number %d \n", id);
	printf("Hello I'm thread number %d, (cnt = %d)\n",id, cnt++); 
	pthread_exit(NULL);
}
