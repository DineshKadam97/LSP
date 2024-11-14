// A program to demonstrate the failure cases of an read() system call using switch case and errno function

#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	int fd, iRet;
	char FileName[25];
	char Buffer[1024];

	printf("Please, enter the name of the file\n");
	scanf("%s",FileName);
	
	fd = open(FileName,O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	printf("File is opened succesfully with FD : %d\n",fd);

	iRet = read(fd,Buffer,sizeof(Buffer));
	if(iRet == -1)
	{
		printf("Unable to read from the file\n");

		switch(errno)
		{
			case EACCES : fprintf(stderr,"ERROR : PERMISSION DENIED\n");
                          break;

		    case EBADF : fprintf(stderr,"ERROR : INVALID FILE DESCRIPTOR\n");
                          break;
		    
			case EFAULT : fprintf(stderr,"ERROR : INVALID BUFFER\n");
                          break;
			
			case EINTR : fprintf(stderr,"ERROR : INTERRUPTED BY SIGNAL HANDLER\n");
                          break;

			case EINVAL : fprintf(stderr,"ERROR : INVALID FILE NAME\n");
                          break;

		    case EIO : fprintf(stderr,"ERROR : I/O ERROR\n");
                          break;
			
			default     : fprintf(stderr,"ERROR : FILE CAN NOT BE READ\n");
		}

		return -1;
	}

	printf("%d bytes sucessfully read\n",iRet);

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