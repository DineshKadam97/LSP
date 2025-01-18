///////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name and copy first 10 bytes
//                     from all regular files into newly created file named as Demo.txt.
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    
    char Buffer[10];
    char FileName[256];
    struct stat sobj;

    DIR *dp = NULL;

    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd2 = creat("Demo.txt", 0777);
    fd2 = open("Demo.txt", O_RDWR | O_APPEND);
    if(fd2 == -1)
    {
        printf("Unable to open Demo.txt\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
       printf("Unable to open the directory\n");
       return -1;
    }    

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(FileName, "%s/%s", argv[1], entry->d_name);
        
        stat(FileName, &sobj);

        fd1 = open(FileName, O_RDONLY);
        read(fd1, Buffer, 10);
        write(fd2, Buffer, 10);
    }

    printf("Data is written succesfully in Demo.txt\n");

    return 0;
}