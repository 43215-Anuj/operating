#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"\nFork Failed");
		return 1;
	}
	else if(pid==0)
	{
		printf("\nChild Process Executing");
	}
	else
	{
		wait(NULL);
		printf("\nChild Complete");
	}
	printf("\n");
	return 0;
}
