#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>

sem_t semaphore;
int num = 2;

void *threadF1(void *arg)
{
	int i;
	if(num != 0)
	{
		sem_wait(&semaphore);
		num--;
		printf("thread 1 using toilet.\n");

		printf("thread 1 finished using toilet.\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num == 0)
	{
		printf("thread 1 waiting for toilet.\n");
		
		while(num==0){}
		sem_wait(&semaphore);
		num--;

		printf("thread 1 finished using toilet.\n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void *threadF2(void *arg)
{
        int i;
        if(num != 0)
        { 
                sem_wait(&semaphore);
		num--;
                printf("thread 2 using toilet.\n");

                printf("thread 2 finished using toilet.\n");
                num++;
                sem_post(&semaphore);
        }
	else if(num == 0)
        {
                printf("thread 2 waiting for toilet.\n");

                while(num==0){}
                sem_wait(&semaphore);
		num--;
                printf("thread 2 finished using toilet.\n");
                num++;
                sem_post(&semaphore);
        }
        return NULL;
}

void *threadF3(void *arg)
{
        int i;
        if(num != 0)
        { 
                sem_wait(&semaphore);
		num--;
                printf("thread 3 using toilet.\n");

                printf("thread 3 finished using toilet.\n");
                num++;
                sem_post(&semaphore);
        }
	else if(num == 0)
        {
                printf("thread 3 waiting for toilet.\n");

                while(num==0){}
                sem_wait(&semaphore);
		num--;
                printf("thread 3 finished using toilet.\n");
                num++;
                sem_post(&semaphore);
        }
        return NULL;
}

int main()
{
	pthread_t thread1, thread2, thread3;
	sem_init(&semaphore, 0, num);
	printf("Semaphore test Start!\n");

	pthread_create(&thread1, NULL, threadF1, NULL);
	pthread_create(&thread2, NULL, threadF2, NULL);
	pthread_create(&thread3, NULL, threadF3, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("All threads finsihed using toilet.\n");

	sem_destroy(&semaphore);

	return 0;
}	
