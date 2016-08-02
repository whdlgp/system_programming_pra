#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void func1(void);
void func2(void);

int main(void)
{
	printf("hello!\n");
	atexit(func1); //소멸자 비스무리하게 함수등록
	atexit(func2);

	printf("bye!\n");

	//_exit(0); //등록된 함수들 호출하지 않으면서 종료
	exit(0); //등록된 함수들 호출하면서 종료
			//등록된 순서의 반대순으로 호출
}

void func1(void)
{
	printf("func1\n");
}

void func2(void)
{
	printf("func2\n");
}
