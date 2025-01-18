////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name user and write string in 
//                     that file.
//
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char *Data = NULL;
    int iSize = 0;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }
    
    fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Please, enter the number of bytes that you want to type\n");
    scanf("%d", &iSize);

    Data = (char *)malloc(iSize);

    printf("Please, enter the string\n");
    scanf(" %[^'\n']s", Data);

    write(fd, Data, strlen(Data));
    
    printf("String is written succesfully in the given file\n");
    
    
    close(fd);
    return 0;
}
