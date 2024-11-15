/*
	This program demonstates scatter/Gather I/O
	In this program we are writing vector og buffers in file withe the help of writev() system call.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/uio.h>	// for writev system call

int main()
{

	// Create three variables of iovec structure which maintains information about the buffer
	struct iovec iobj[3];
	/*
		struct iovec
		{
			void *iov_base;	// Base address of buffer
			size_t iov_len;	// Size of buffer	
		};
	*/

	int fd;
	int ret;

	char buff1[] = "First string.";
	char buff2[] = "Second string";
	char buff3[] = "Third string.";

	// Opening newly created file
	fd = open("writev_demo.txt",O_WRONLY | O_CREAT);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	// Initializing the iovec struture
	iobj[0].iov_base = buff1;
	iobj[0].iov_len = strlen(buff1);

	iobj[1].iov_base = buff2;
	iobj[1].iov_len = strlen(buff2);

	iobj[2].iov_base = buff3;
	iobj[2].iov_len = strlen(buff3);

	ret = writev(fd,iobj,3);
	// First parameter :	File descriptor
	// Second parameter :	Base address of iovec structures array
	// Third parameter :	Number of elements in iovec strucre array	
	if(ret == -1)
	{
		printf("Error in writev\n");
		return -1;
	}
	printf("data written successfully\n");
	return 0;
}
