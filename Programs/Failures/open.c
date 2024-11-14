// A program to demonstrate the failure cases of an open() system call using perror() function

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
		perror("Error");                       // It will display the reason why the file is not opened

		return -1;
	}

	printf("File is opened succesfully with FD : %d\n",fd);

	close(fd);

	return 0;
}

//fprintf(stderr,"Error is : %s\n",strerror(errno));  stderr : standard error

