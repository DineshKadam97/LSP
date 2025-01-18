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
    int fd = 0;
    int iRet = 0;
    int A =0, B = 0, Ans = 0;

    char Buffer[BLOCKSIZE];

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    FILE *fileIn = freopen(argv[1],"r", stdin);
    if(fileIn == NULL)
    {
      printf("Failed to open the output file\n");
      return -1;
    }
    
    scanf("%d",&A);
    scanf("%d",&B);
    
    FILE *fileOut = freopen(argv[2],"w", stdout);
    if(fileOut == NULL)
    {
      printf("Failed to open the input file\n");
      return -1;
    } 
    
    Ans = A+B;
    
    printf("Addition is : %d\n", Ans);
    
    fclose(fileIn);
    fclose(fileOut);

    return 0;
}
