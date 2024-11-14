// A program to demonstrate the failure cases of an creat() system call using fprintf() and strerror() function

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
	
	fd = creat(FileName,0777);
	if(fd == -1)
	{
		printf("Unable to creat file\n");
		fprintf(stderr,"Error is : %s\n",strerror(errno));      // It will display the reason why the file is not created
		return -1;
	}

	printf("File is created succesfully with FD : %d\n",fd);

	close(fd);

	return 0;
}