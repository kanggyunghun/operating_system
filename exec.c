#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	//int main(int argc, char *argv[])
	printf("execl start!!\n");
	execl("/bin/ls","ls","-l",NULL);
	//system("/bin/ls -l");
	//system func takes process name for argument and execute.
	//int system(const char *argv); if fail 0, success positive value
	printf("if you read this message, fail creating execl func..\n");
	
	return 0;
}
