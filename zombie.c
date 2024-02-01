#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t childPid;
	childPid = fork();

	if(childPid > 0)
	{
		printf("parent pid : %d\n", getpid());
		sleep(30);
		printf("parent  terminate\n");
		exit(0);	
	}
	else if(childPid == 0)
	{
		printf("child\n");
		sleep(1);
		printf(":child terminate\n");
		exit(0);
	}
	else
	{
		perror("fork Fail!\n");
		return -1;
	}
}
