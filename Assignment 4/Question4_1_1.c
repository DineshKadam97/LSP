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
  int fdIn = 0, fdOut = 0;
  int iRet = 0;
  int A =0, B = 0, Ans = 0;

  char Buffer[BLOCKSIZE];

  if(argc != 3)
  {
    printf("Invalid number of arguments\n");
    return -1;
  }

  fdIn = open(argv[1],O_RDONLY);
  if(fdIn == 0)
  {
    printf("Unable to open the input file\n");
    return -1;
  }
    
  fdOut = open(argv[2],O_WRONLY | O_APPEND);
  if(fdOut == 0)
  {
    printf("Unable to open the output file\n");
    return -1;
  } 

  dup2(fdIn, STDIN_FILENO);

  scanf("%d",&A);
  scanf("%d",&B);
    
  dup2(fdOut,STDOUT_FILENO);
    
  Ans = A+B;
    
  printf("Addition is : %d\n", Ans);
  
  return 0;

}
