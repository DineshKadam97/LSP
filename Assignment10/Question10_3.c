//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is which creates one thread and we have to pass one 
//                     parameter to that thread from one thread.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<pthread.h>

void * Thread_Proc(void * ptr)
{
    printf("Inside Thread\n");

    char ch = (char *) ptr;
    
    printf("Value Passed to the thread is : %c\n",ch);

    pthread_exit(NULL);
}

int main()
{
    int iRet = 0;
    char Value = '\0';

    pthread_t TID;

    iRet = pthread_create(&TID,
                          NULL,
                          Thread_Proc,
                          (char *)'A');
    
    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created succesfully with ID : %ld\n", TID);

    pthread_join(TID, NULL);


    printf("End of main thread\n");
    
    return 0;
}
