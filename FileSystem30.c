#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR | O_CREAT);
    if(fd != -1)
    {
        printf("File is succesfully opened with fd %d \n",fd);
    }
    
    return 0;
}