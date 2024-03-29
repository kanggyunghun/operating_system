#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *cancel_thread(void *arg)
{
	int i, state;
	for(i=0;;i++)
	{
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &state);
		printf("Thread: cancel state disabled\n");
		sleep(1);
		pthread_setcancelstate(state, &state);
		printf("Thread: cancel state enabled\n");
		if(i%5 == 0)
			pthread_testcancel;
	}
	return arg;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	int arg, status;
	void *result;

	if(argc < 2)
	{
		fprintf(stderr, "USAGE: cancelthread time(sec)\n");
		exit(1);
	}
	
	status = pthread_create(&tid, NULL, cancel_thread, NULL);

	if(status !=0)
	{
		fprintf(stderr, "create thread: %d", status);
		exit(1);
	}
	pthread_detach(tid, &result);
	arg = atoi(argv[1]);
	sleep(arg);

	status = pthread_cancel(tid);
	if(status != 0)
	{
		fprintf(stderr, "Join thread: %d", status);
		exit(1);
	}
	return (int)result;
}

