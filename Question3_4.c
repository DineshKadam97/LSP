///////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and delete all  
//                     empty files from the directory.
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    char FileName[256];
    struct stat sobj;

    DIR *dp = NULL;

    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
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

        if(sobj.st_size == 0)
        {
            remove(FileName);
        }
    }

    printf("Files with size of 0 bytes are deleted succesfully\n");
    
    closedir(dp);

    return 0;
}
