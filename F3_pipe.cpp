
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#define Buffer_Size 25
#define READ_END 0
#define WRITE_END 1
int main()
{
	char write_msg[Buffer_Size]="Hello";
	char read_msg[Buffer_Size];
	int fd[2];
	pid_t pid;
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"Pipe failed");
		return 1;
	}
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	if(pid==0)
	{
		close(fd[READ_END]);
		write(fd[WRITE_END],write_msg,strlen(write_msg));
		close(fd[WRITE_END]);
	}
	else
	{
		close(fd[WRITE_END]);
		read(fd[READ_END],read_msg,Buffer_Size);
		printf("read %s",read_msg);
		close(fd[READ_END]);
	}
	return 0;
}
