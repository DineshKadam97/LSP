// This program demonstates truncate and ftruncate system call
// By using truncate or ftruncate function we can truncate the 
// file from specified offset.
// If we use O_TRUNK option while opening the file whole file 
// gets truncated and file size become zero.
// But using this system calls we can truncate file from 
// specified offset from end

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main( )
{
	int ret;
	int fd;

	// By using this function we can truncate the file after file offset 10
	ret = truncate("Demoo.txt",10);
	if(ret == -1)
	{
		printf("Unable to truncate file\n");
	}

	// For the truncaion purpose file must be opened in write mode
	fd = open("Demoo.txt",O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file\n");
	}

	// If file is already opened then instd of calling truncate we can call
	// ftruncate which accept file descriptor as a first parameter

	// In this case file gets truncated after file offset 7.
	ret = ftruncate(fd,7);
	if(ret == -1)
	{
		printf("Unable to truncate file\n");
	}
	printf("File truncated. \n");

	return 0;
}
