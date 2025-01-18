//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is used to get thread ID inside its thread function.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<pthread.h>

void * GetThreadID(void * ptr)
{
    printf("Inside Thread\n");
    
    pthread_t TID = pthread_self();

    printf("Thread ID is : %ld\n", (unsigned long)TID);

    pthread_exit(0);
}

int main()
{
    int iRet = 0;
    char Value = '\0';

    pthread_t TID;

    iRet = pthread_create(&TID,
                          NULL,
                          GetThreadID,
                          NULL);
    
    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created succesfully with ID : %ld\n", TID);

    pthread_join(TID,NULL);

    printf("End of main thread\n");
    
    return 0;
}
