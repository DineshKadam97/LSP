#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);

    if(S_ISREG(sobj.st_mode))
    {
        printf("Its a regular file\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Its a directory\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Its a symbolic link\n");
    }

    return 0;
}