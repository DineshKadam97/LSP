// A program to demonstrate the failure cases of an read() system call using using strerror(errno) function

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
	char Buffer[1024];

	printf("Please, enter the name of the file\n");
	scanf("%s",FileName);
	
	fd = open(FileName,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		perror("Error");                       // It will display the error, why the file is not opened
		return -1;
	}

	printf("File is opened succesfully with FD : %d\n",fd);

	iRet = read(fd,Buffer,sizeof(Buffer));
	if(iRet == -1)
	{ 
	   printf("Unable to read from the file\n");    
	   fprintf(stderr,"ERROR is : %s\n",strerror(errno));    // It will display the error, why we can not read the data
       return -1;
	}

	printf("%d bytes sucessfully read\n",iRet);

	close(fd);

	return 0;
}
