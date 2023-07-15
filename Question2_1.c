////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name from user and read the whole
//                     file.
//
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[BLOCKSIZE];
    int iRet = 0;

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("unable to read file\n");
        return -1;
    }
    
    while(1)
    {
        iRet = read(fd, Buffer, sizeof(Buffer));

        if(iRet == 0)
        {
            break;
        }

        write(1, Buffer, iRet);
    }

    close(fd);
    printf("\n");

    return 0;
}