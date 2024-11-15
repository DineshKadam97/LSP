/*
	This program demonstates scatter/Gather I/O
	In this program we are reading in vector of buffers from file with the help of readv() system call.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/uio.h>	// for writev system call
#include<unistd.h>

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
	int ret,i;

	char buff1[13];
	char buff2[13];
	char buff3[13];

	// Opening newly created file
	fd = open("writev_demo.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	// Initializing the iovec struture
	iobj[0].iov_base = buff1;
	iobj[0].iov_len = sizeof(buff1);

	iobj[1].iov_base = buff2;
	iobj[1].iov_len = sizeof(buff2);

	iobj[2].iov_base = buff3;
	iobj[2].iov_len = sizeof(buff3);

	ret = readv(fd,iobj,3); //scattered gathered IO
	// First parameter :	File descriptor
	// Second parameter :	Base address of iovec structures array
	// Third parameter :	Number of elements in iovec strucre array	

	if(ret == -1)
	{
		printf("Error in writev\n");
		return -1;
	}

	for(i=0; i<3; i++)
	{
		printf("%d : %s\n",i,(char *)iobj[i].iov_base);
	}

	close(fd);
	return 0;
}
