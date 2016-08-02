#define NITERS 100000000
#include <stdio.h>
#include <pthread.h>


unsigned int cnt = 0;
void* count(void *data);
pthread_mutex_t mutex; //뮤텍스 객체 생성


int main(void)
{
	pthread_t tid1, tid2;
	pthread_mutex_init(&mutex, NULL); //뮤텍스 설정 초기화
	pthread_create(&tid1, NULL, count, NULL);
	pthread_create(&tid2, NULL, count, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&mutex); //뮤텍스 설정 삭제

	if(cnt != (unsigned)NITERS*2)
	{
		printf("BOOM! cnt = %d\n", cnt);
	}
	else
	{
		printf("OK! cnt = %d\n", cnt);
	}

	return 0;
}

void* count(void* data)
{
	int i;
	for(i = 0; i < NITERS; i++)
	{
		pthread_mutex_lock(&mutex);
		cnt++;
		pthread_mutex_unlock(&mutex);
	}
}
