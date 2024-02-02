#include<pthread.h>
#include<stdio.h>

void *threadRoutine(void *arg)
{
	pthread_t tid = pthread_self();
	//TID return and print
	printf("thread ID :: %lu\n", tid);
	while(1)
	{
		printf("a\n");
	}
	return NULL;
}

int main()
{
	pthread_t threadID;
	char tmp[10];

	scanf("%s", tmp);
	pthread_create(&threadID, NULL, threadRoutine, NULL);

	scanf("%s", tmp);
	pthread_detach(threadID);

	while(1)
	{
		printf("b\n");
	}
}
