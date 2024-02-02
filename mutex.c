#include<pthread.h>
#include<stdio.h>

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;
int sum2 = 0;

void *threadRoutine(void *argumentPointer)
{
	int i;
	pthread_mutex_lock(&counter_mutex);
	for(i=0; i<1000000; i++)
		sum++;
	pthread_mutex_unlock(&counter_mutex);
	return NULL;
}

void *threadRoutine2(void *argumentPointer)
{
	int i;
	for(i=0; i<1000000; i++)
		sum2++;
}

int main()
{
	pthread_t threadD1, threadD2;
	pthread_t threadD3, threadD4;

	pthread_create(&threadD1, NULL, threadRoutine, NULL);
	pthread_create(&threadD2, NULL, threadRoutine, NULL);

	pthread_create(&threadD3, NULL, threadRoutine2, NULL);
	pthread_create(&threadD4, NULL, threadRoutine2, NULL);


	pthread_join(threadD1, NULL);
	pthread_join(threadD2, NULL);
	pthread_join(threadD3, NULL);
	pthread_join(threadD4, NULL);

	printf("sum result using mutex: %d\n", sum);
	printf("sum result without mutex: %d\n", sum2);

	return 0;
}
