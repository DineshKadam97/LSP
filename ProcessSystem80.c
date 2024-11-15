// Server for named pipe

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
    
    fd = mkfifo(path,0666);
    if(fd == -1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    printf("Server is running and writing the data into named pipe...\n");
    fd = open(path,O_WRONLY);

    write(fd,"Marvellous",10);

    close(fd);
    
    unlink(path);
    
    printf("Data succesfully written in the pipe\n");
    return 0;
}