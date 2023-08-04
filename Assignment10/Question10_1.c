//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is used to create a simple thread using pthread library
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<pthread.h>

void * Thread_Proc(void * ptr)
{
    printf("Inside Thread\n");

    pthread_exit(0);
}

int main()
{
    int iRet = 0;

    pthread_t TID;

    iRet = pthread_create(&TID,
                          NULL,
                          Thread_Proc,
                          NULL);
    
    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created succesfully with ID : %ld\n", TID);

    pthread_join(TID, NULL);
    
    return 0;
}
