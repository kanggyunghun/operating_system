#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t childPid;
	int i;
	childPid = fork();
	if(childPid > 0)
	{
		printf("parent pid: %d\n", getpid());
		sleep(2);
		printf("parent terminate\n");
		exit(0);
	}
	else if(childPid==0)
	{
		printf("child\n");
		for(i = 0; i<10; i++)
		{
			printf("child pid: %d, parent pid: %d\n",getpid(),getppid());
			sleep(1);
		}
		printf("child terminate\n");
		exit(0);
	}
	else
	{
		// fork fail
		 return -1;
	}
	return 0;
}
