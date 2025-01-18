///////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and print all
//                     file names and its types from that directory.
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>


int main(int argc, char *argv[])
{
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
    
    printf("-------------------------------------------------\n");
    printf("\tEntries From the directory %s are  \n", argv[1]);
    printf("-------------------------------------------------\n\n");

    printf("-------------------------------------------------\n");
    printf("    Name of the File \t File Type\n");
    printf("-------------------------------------------------\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%20s   :     %u \n", entry->d_name, entry->d_type);
    }
    printf("-------------------------------------------------\n");
    
    closedir(dp);

    return 0;
}
