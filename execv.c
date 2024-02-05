#include<stdio.h>
#include<unistd.h>

int main()
{
	char *argv[] = {"ls", "-l", NULL};
	printf("execv start!!\n");
	execv("/bin/ls", argv);
	// execl has to have arguments one by one
	// for execv, it's pointer array
	// same as execl("/bin/ls", "ls", "-l", NULL);
	printf("if you read this message, fail creating execv func..\n");
	return 0;
}	
