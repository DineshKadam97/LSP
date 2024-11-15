#include <fcntl.h>
#include<stdio.h>

int main(void)
{
	int fd;
	int ret;
	int offset;

	char buff[200];

	// If file is opened in read mode we can read the contents from 0 byte offset
	fd = open("new.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}

	// We can read the contents from teh file by using read system call
	// which accept first parameter as file descriptor	
	// second parameter is empty buffer
	// Third parameter is number of bytes to read

	ret = read(fd,buff,20);

	// read system call returns no of bytes successfully read.
	// It returns -1 if it fails to read
	// It returns 0 if it reach end of file whicle reading

	if(ret != 20)
	{
		printf("Unable to read contents\n");
	}

	printf("Read contents are \n %s\n",buff);

	// After reading 20 bytes current offset is changed by 20 bytes

	offset = lseek(fd,0,SEEK_CUR);
	printf("After reading 20 bytes current byte offset is %d\n",offset);

	return 0;
}

