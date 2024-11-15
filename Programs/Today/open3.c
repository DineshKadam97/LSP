// A program to demonstrate the failure cases of an open() system call using switch case and errno function

#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	int fd;
	char FileName[25];

	printf("Please, enter the name of the file\n");
	scanf("%s",FileName);
	
	fd = open(FileName,O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open the file\n");

		switch(errno)
		{
			case EACCES : fprintf(stderr,"ERROR : PERMISSION DENIED\n");
                          break;

		    case ENOENT : fprintf(stderr,"ERROR : FILE DOESNT EXIST\n");
                          break;
		    
			case EISDIR : fprintf(stderr,"ERROR : ITS A DIRECTORY\n");
                          break;
			
			case ENOSPC : fprintf(stderr,"ERROR : DEVICE MEMORY IS FULL\n");
                          break;

			case EINVAL : fprintf(stderr,"ERROR : INVALID FILE NAME\n");
                          break;

		    case EIO : fprintf(stderr,"ERROR : I/O ERROR\n");
                          break;
			
			default     : fprintf(stderr,"ERROR : FILE CAN NOT BE OPENED\n");
		}
		return -1;
	}

	printf("File is opened succesfully with FD : %d\n",fd);

	close(fd);

	return 0;
}

//printf("Error is : %s\n",strerror(errno)); 

//EACCES : PERMISSION DENIED
//EISDIR : ITS A DIRECTORY
//EINTR : INTERRUPTED BY SIGNAL HANDLER
//EINVAL : INVALID FILE NAME
//ENFILE : SYSTEM LIMIT IS REACHED TO OPEN FILES
//ENOENT : FILE DOESNT EXIST
//ENOMEM : INSUFFICIENT KERNEL MEMORY WAS AVAILABLE
//ENOSPC : DEVICE MEMORY IS FULL
//ENOTDIR : ITS NOT A DIRECTORY
//ENXIO : ITS A DEVICE SPECIAL FILE
//EEXIST : FILE IS ALREADY EXISTING