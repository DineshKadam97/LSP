/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates 2 threads using thread API, where one thread counts 
//                     number of capital letters from Demo.txt file and other thread count number of small 
//                     letters from the same file
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>   

void* ThreadProc1(void *ptr)    
{
    printf("Inside Thread 1\n");

    int fd1 = (int)ptr;

    int iCnt = 0;
    int iRet = 0;
    int i = 0;
    char Buffer[1024];

    while((iRet = read(fd1, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of capital characters are %d\n",iCnt);
    pthread_exit(NULL);
}

void* ThreadProc2(void *ptr)    
{
    printf("Inside Thread 2\n");
    int fd2 = (int)ptr;

    int iCnt = 0;
    int iRet = 0;
    int i = 0;
    char Buffer[1024];

    while((iRet = read(fd2, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }
  
    printf("Number of small characters are %d\n",iCnt);
    pthread_exit(NULL);
}

int main()
{
    int fd1 = 0, fd2 = 0;

    fd1 = open("Demo.txt", O_RDONLY);
    if(fd1 == 0)
    {
        printf("Unable to open Demo.txt\n");
        return -1;
    }

    pthread_t TID1, TID2;
    int Ret1 = 0, Ret2 = 0;

    Ret1 = pthread_create(&TID1,  
                          NULL, 
                          ThreadProc1,
                          (int *)fd1);        

    
    if(Ret1 != 0)
    {
        printf("Unable to create thread1\n");
        return -1;
    }

    printf("Thread1 is created with ID : %ld\n", TID1);

    fd2 = open("Demo.txt", O_RDONLY);
    if(fd2 == 0)
    {
        printf("Unable to open Demo.txt\n");
        return -1;
    }

    Ret2 = pthread_create(&TID2,   
                          NULL,  
                          ThreadProc2, 
                          (int *)fd2);        

    
    if(Ret2 != 0)
    {
        printf("Unable to create thread1\n");
        return -1;
    }

    printf("Thread2 is created with ID : %ld\n", TID2);
    
       
    pthread_join(TID2, NULL); 
    pthread_join(TID1, NULL);

    close(fd1);  
    close(fd2);   

    printf("End of main thread\n");

    pthread_exit(NULL);

    return 0;
}
