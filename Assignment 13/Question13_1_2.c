//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates two process as reader and writer and that process should 
//                     communicate with each other using FIFO.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Server for named pipe

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h> 
#include<string.h>   

int main()
{
    int fd = 0;

    char * path = "/tmp/mypipe";
    
    fd = mkfifo(path, 0666);
    if(fd == -1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    printf("Server is running and writing the data into named pipe.....\n");
    fd = open(path,O_WRONLY);

    write(fd,"Bharat",6);

    close(fd);

    unlink(path);

    printf("Data is written succesfully in the pipe\n");

    return 0;
}