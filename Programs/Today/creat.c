// A program to demonstrate the failure cases of an creat() system call using perror() function

#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	int fd;
	char FileName[25];

	printf("Please, enter the name of the file\n");
	scanf("%s",FileName);
	
	fd = creat(FileName,0666);
	if(fd == -1)
	{
		printf("Unable to creat file\n");
		perror("creat");                       // It will display the reason why the file is not created
		return -1;
	}

	printf("File is created succesfully with FD : %d\n",fd);

	close(fd);

	return 0;
}

//fprintf(stderr,"Error is : %s\n",strerror(errno));  stderr : standard error

