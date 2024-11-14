// A program to demonstrate the failure cases of an open() system call using strerror(errno) function

#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	int fd;
	char FileName[25];

	printf("Please, enter the name of the file\n");
	scanf("%s",FileName);
	
	fd = open(FileName,O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		fprintf(stderr,"Error is : %s\n",strerror(errno)); // we can use printf too, but using fprintf() the standard way

		return -1;
	}

	printf("File is opened succesfully with FD : %d\n",fd);

	close(fd);

	return 0;
}

//printf("Error is : %s\n",strerror(errno)); 