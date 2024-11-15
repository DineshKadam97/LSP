/*
	Write a program which create hole of size 1kb at the end of file.
*/

#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	char buff[50] = {' '};
	
	if(argc != 2)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}

	// If file is opened in read mode we can read the contents from 0 byte 		offset
	fd = open(argv[1],O_WRONLY);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}

	// As we want to create hole at the end of file we have to perform 	appropriate lssek operation as
	lseek(fd,1024,SEEK_END);
	
	// write 1 byte at the end of file to apply the effect of lseek.
	write(fd,buff,1);
	
	close(fd);
	return 0;
}
