#include <fcntl.h>
#include<stdio.h>

int main(void)
{
	int fd;
	int ret;
	int offset;

	char buff[] = "New contens in the file\n";
	char buff2[sizeof(buff)];

	// If file is opened in write mode we can read the contents from 0 byte offset
	fd = open("file.txt",O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}

	// We can write the contents to the file by using write system call
	// which accept first parameter as file descriptor
	// second parameter is filled buffer
	// Third parameter is number of bytes to write

	ret = write(fd,buff,sizeof(buff));

	// read system call returns no of bytes successfully write.
	// It returns -1 if it fails to write

	if(ret != sizeof(buff))
	{
		printf("Unable to write contents\n");
	}

	lseek(fd,0,SEEK_SET);

	ret = read(fd,buff2,sizeof(buff2));
	printf("Written contents are : %s\n",buff2);
	close(fd);
	close(ret);

	return 0;
}
