// A program to demonstrate the failure cases of an write() system call using using strerror(errno) function

#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	int fd = 0;
	int iRet = 0;
	char FileName[25];
	int Buffer;

	printf("Please, enter the name of the file\n");
	scanf("%s",FileName);
	
	fd = open(FileName,O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		perror("Error");                       // It will display the error, why the file is not opened
		return -1;
	}

	printf("File is opened succesfully with FD : %d\n",fd);

	iRet = write(fd,Buffer,sizeof(Buffer));
	if(iRet == -1)
	{ 
		printf("Unable to write into file\n");
		fprintf(stderr,"ERROR is : %s\n",strerror(errno));    // It will display the error, why we can not write the data
		return -1;
	}

	printf("%d bytes sucessfully read\n",iRet);

	close(fd);

	return 0;
}