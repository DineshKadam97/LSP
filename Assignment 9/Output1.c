#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>


int main()
{
    printf("Inside Child Process - PID of Parent process is  %d\n", getppid());

    int fd = 0;

    DIR *dp = NULL;
    struct dirent *entry = NULL;

    struct stat sobj;

    dp = opendir("/home/dinesh/Desktop");
    if(dp == NULL)
    {
        printf("Unable to open Desktop\n");
        return -1;
    }
    
    fd = open("/home/dinesh/Desktop/Demo.txt", O_RDWR | O_APPEND);
    if(fd == -1)
    {
        printf("Unable to open file Demo.txt\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {    
        write(fd, entry->d_name, strlen(entry->d_name));
    }

    printf("Data is written inside Demo.txt");
    
    return 0;
}