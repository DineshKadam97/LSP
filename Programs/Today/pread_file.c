//Program to demostrate pread().
#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main(void)
{
int fd;
int ret;
int offset;

char buff[500];

// If file is opened in read mode
fd = open("file.txt",O_RDONLY);
if(fd == -1)
{
	printf("Unable to open file \n");
	return -1;
}

// When we use read and lseek system call it not provides atomic behaviour.
// When multiple processess can access the same file then there can be a problem.
// which can be avoided using pread system call which gives effect of lseek and read atomically.

// Parameters of pread system call is same but only diffrence is in last parameter
// Last parameter is offset from which we have to read
//close(fd);
ret = pread(fd,buff,sizeof(buff),10); //atomic operation lseek and raed together

// pread system call returns no of bytes successfully read.

if(ret != sizeof(buff))
{
	printf("Unable to write contents\n");
}

printf("\nRead contents are \n %s \n\n",buff);

close(ret);

return 0;

}
