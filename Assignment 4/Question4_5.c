////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name and position from user
//                     and read 20 bytes from that position.
//
///////////////////////////////////////////////////////////////////////////////////////////

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
    iRet = read(fd, Buffer, 20);

    printf("%d bytes read succesfully\n", iRet);
    write(1, Buffer, 20);
    printf("\n");

    return 0;
}
