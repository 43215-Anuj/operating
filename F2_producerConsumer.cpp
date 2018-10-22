#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#define Buffer_Size 5
typedef struct
{
}item;
int buffer[Buffer_Size];
int in=0;int out=0;
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"\nFork Failed");
		return 1;
	}
	else if(pid!=0)
	{
		int nextProduced;
		while(true)
		{
			printf("\nin/out of pr%d-%d\n",in,out);
			fflush(stdout);
			while(((in+1)%Buffer_Size)==out);
			nextProduced=getchar();
			printf("\nItemProduced is-%d",nextProduced);
			buffer[in]=nextProduced;
			in=(in+1)%Buffer_Size;
		}
	}
	else
	{
		int nextConsumed;
		while(true)
		{
			printf("\ni/o of c%d-%d\n",in,out);
			fflush(stdout);
			while(in==out);
			nextConsumed=buffer[out];
			printf("Consumed");
			fflush(stdout);
			out=(out+1)%Buffer_Size;
		}
	}
	printf("\n");
	return 0;
}
