////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept 2 file names from user and copy contents of
//                     existing file into newly created file.
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int iRet = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 3)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    fdSource = open(argv[1], O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open file %s\n", argv[1]);
        return -1;
    }

    fdDest = creat(argv[2], 0777);

    while((iRet = read(fdSource, Buffer, sizeof(Buffer))) != 0)
    {
        write(fdDest, Buffer, iRet);
    }

    printf("Content of %s is copied succesfully into %s\n", argv[1], argv[2]);

    close(fdDest);
    close(fdSource);

    return 0;
}
