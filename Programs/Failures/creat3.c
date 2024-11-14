// A program to demonstrate the failure cases of an creat() system call using switch case and errno function

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
	
	fd = creat(FileName,0666);
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

		    case EEXIST : fprintf(stderr,"ERROR : FILE IS ALREADY EXISTING\n");
                          break;
			
			case ENOSPC : fprintf(stderr,"ERROR : DEVICE MEMORY IS FULL\n");
                          break;

		    case EFAULT : fprintf(stderr,"ERROR : BAD ADDRESS\n");
                          break;

		    case EINTR : fprintf(stderr,"ERROR : INTERRUPTED BY SYSTEM CALL\n");
                          break;

			case EINVAL : fprintf(stderr,"ERROR : INVALID FILE NAME\n");
                          break;

		    case EROFS : fprintf(stderr,"ERROR : READ-ONLY FILE SYSTEM\n");
                         break;

		    case EIO : fprintf(stderr,"ERROR : I/O ERROR\n");
                       break;
			
			default     : fprintf(stderr,"ERROR : UNKNOWN ERROR\n");
		}
		return -1;
	}

	printf("File is created succesfully with FD : %d\n",fd);

	close(fd);

	return 0;
}