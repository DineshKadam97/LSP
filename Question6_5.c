//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name and offset, remove all the data 
//                     from that offset.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int iRet = 0;

    char Buffer[BLOCKSIZE];

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    lseek(fd, atoi(argv[2]), SEEK_SET);
    remove(argv[1]);

    return 0;
}
