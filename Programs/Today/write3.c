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
		printf("Unable to write into file\n");

		switch(errno)
		{
			case EACCES : fprintf(stderr,"ERROR : PERMISSION DENIED\n");
                          break;

		    case EBADF : fprintf(stderr,"ERROR : INVALID FILE DESCRIPTOR\n");
                          break;
		    
			case EFBIG : fprintf(stderr,"ERROR : FILE IS TOO LARGE TO WRITE\n");
                          break;
			
			case EINTR : fprintf(stderr,"ERROR : INTERRUPTED BY SYSTEM CALL\n");
                          break;

			case EINVAL : fprintf(stderr,"ERROR : INVALID ARGUMENT\n");
                          break;

		    case EIO : fprintf(stderr,"ERROR : I/O ERROR\n");
                          break;

			case ENOSPC : fprintf(stderr,"ERROR : RESOUCE TEMPORORILY NOT AVAILABLE\n");
                          break;
			
			default     : fprintf(stderr,"ERROR : CAN NOT WRITE INTO FILE\n");
		}
        
		close(fd);
		return -1;
	}

	printf("%d bytes sucessfully read\n",iRet);

	close(fd);

	return 0;
}