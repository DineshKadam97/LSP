////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name and number of bytes from user
//                     and read that number of bytes from the file.
//
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    int fd = 0;
    int mode = 0;
    int iRet = 0;
    char *Buffer = NULL;

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is opened succesfully with FD %d\n", fd);
    }

    Buffer = (char *)malloc(atoi(argv[2]));

    iRet = read(fd, Buffer, atoi(argv[2]));

    printf("%d bytes from the file are read succesfully\n", iRet);
    printf("Data from the file is : \n%s\n", Buffer);
    
    close(fd);

    return 0;
}
