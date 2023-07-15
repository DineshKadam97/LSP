////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name from user and mode from user 
//                     and open that file in specified mode.
//
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int mode = 0;

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    if(strcmp(argv[2], "read") == 0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2], "write") == 0)
    {
        mode = O_WRONLY;
    }
    else if(strcmp(argv[2], "read-write") == 0)
    {
        mode = O_RDWR;
    }
    else
    {
        mode = O_RDONLY;
    }

    fd = open(argv[1], mode);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is opened succesfully with FD %d\n", fd);
    }

    close(fd);

    return 0;
}
