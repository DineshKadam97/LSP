////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program to demonstrate the concept of IO redirection.
//
///////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdIn = 0;
    int fdOut = 0;
    int iRet = 0;
    int A =0, B = 0, Ans = 0;

    char Buffer[BLOCKSIZE];
    char Data[25];

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fdIn = open(argv[1],O_RDONLY);
    if(fdIn == -1)
    {
      printf("Unable to open file\n");
      return -1;
    }

    read(fdIn,Buffer,sizeof(Buffer));
    
    scanf("%d",&A);
    scanf("%d",&B);
    
    fdOut = open(argv[2],O_RDONLY);
    if(fdOut == -1)
    {
      printf("Unable to open file\n");
      return -1;
    } 
    
    Ans = A+B;
    
    sprintf(Data,"Addition is : %d\n", Ans);

    write(fdOut,Data,strlen(Data));
    
    close(fdIn);
    close(fdOut);

    return 0;
}
