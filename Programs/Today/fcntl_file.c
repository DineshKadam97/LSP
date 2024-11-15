// Program to demonstrate fcntl()

#include <stdio.h>
#include <fcntl.h>
 
int main()
{
	int val;
	int fd;
	int newfd;

	fd = open("file.txt",O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
	}

	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
	{
		printf("Error in fcntl\n");
	}

	// Switch case use to check the access mode of file
	// O_ACCMODE is a macro stands for a mask that can be bitwise-ANDed 
	// with the file status flag value to produce a value representing 
	// the file access mode.
	switch (val & O_ACCMODE) 
	{
		case O_RDONLY:
				printf("read only mode\n");
			break;

		case O_WRONLY: 
				printf("write only mode\n");
			break;

 
		case O_RDWR:
				printf("read write mode\n");
			break;

		default:
				printf("unknown access mode\n");
	}

	if (val & O_APPEND)
	{
		printf(", append");
	}

	if (val & O_NONBLOCK)
	{
		printf(", nonblocking");
	}

	// The another use of fcntl system call is to duplicate the file descriptor
	// Means by using fcntl we can get same efect as dup or dup2

	newfd = fcntl(fd, F_DUPFD, 0);

	// it is equivalent to : 
	// newfd = dup(fd);

	printf("Old file descriptor is %d and new is %d\n",fd,newfd);

	// Similarly, we can get same effect as dup2

	close(8);
	newfd = fcntl(fd, F_DUPFD, 8);
	// it is equivalent to dup2(filedes, filedes2);

	printf("Old file descriptor is %d and new is %d\n",fd,newfd);
	return 0;
}
