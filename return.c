#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void * threadRoutine(void *arg)
{
	long argument;
	argument = *((long *)arg);
	return (void*)(argument +900);
}

int main()
{
	pthread_t threadID;
	printf("Create thread!\n");
	long argument = 100;
	int status;
	void *value;

	status = pthread_create(&threadID, NULL, threadRoutine, (void*)&argument);

	printf("Main Thread is now waiting for Thread!\n");

	pthread_join(threadID, &value);

	printf("Return value(0: success) :: %d\n", status);
	printf("receive value :: %Id\n", (long)value);

	return 0;
}
