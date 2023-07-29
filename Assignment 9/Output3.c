#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 1024

int CountSmall(int fd)
{
    int iCnt = 0;
    int iCount = 0;
    int iRet = 0;
    char Buffer[BLOCKSIZE];

    while((iRet = read(fd, Buffer, BLOCKSIZE)) != 0)
    {
        for(iCnt = 0; iCnt < iRet; iCnt++)
        {
            if((Buffer[iCnt] >= 'a') && (Buffer[iCnt] <= 'z'))
            {
                iCount++;
            }
        }
    } 

   return iCount;
}

int main()
{
    int fd = 0;
    int iRet = 0;
    char Buffer[100] = {'\0'};

    printf("Inside Process2, PID of Parent process is  %d\n",getppid());

    fd = open("Hello.txt",O_RDONLY);

    iRet = CountSmall(fd);
    printf("Number of small characters in Hello.txt are : %d\n", iRet);

    fd = open("Count.txt", O_RDWR | O_APPEND);
    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    
    sprintf(Buffer, "Number of small characters in the Hello.txt are : %d\n", iRet);

    write(fd, Buffer, strlen(Buffer));

    printf("Data has been written succesfully in Count.txt\n");


    return 0;
}