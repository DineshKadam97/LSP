//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates two process as reader and writer and that process should 
//                     communicate with each other using FIFO.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Client for named pipe

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    int fd = 0;
    char *path = "/tmp/mypipe";
    char Buffer[100];

    printf("Client is running and reading data from named pipe...\n");
    fd = open(path,O_RDONLY);

    read(fd,Buffer,6);

    printf("Data from pipe is : %s\n",Buffer);
    
    return 0;
}
