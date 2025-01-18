//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is which creates one thread and it accepts one value from
//                     user and it returns same value to the caller thread.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<pthread.h>

void * Thread_Proc(void * ptr)
{
    printf("Inside Thread\n");

    char ch = (char *) ptr;

    printf("Value received from the user is : %c\n", ch);

    pthread_exit(ch);
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

    pthread_join(TID, &Value);

    printf("Value received from the thread is : %c\n", Value);

    printf("End of main thread\n");
    
    return 0;
}