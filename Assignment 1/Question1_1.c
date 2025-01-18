////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name from user and open that file.
//                     
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
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

    close(fd);

    return 0;
}
