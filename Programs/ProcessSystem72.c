#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
  printf("Inside thread 1\n");
  pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
  printf("Inside thread 2\n");
  pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&TID1,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc1, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret1 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread1 is created with ID : %d\n",TID1);

    ret2 = pthread_create(&TID2,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc2, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret2 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread2 is created with ID : %d\n",TID2);

    pthread_join(TID1,NULL); // NULL => second parameter ha (void **) aahe mhnjech pointer to pointer
    pthread_join(TID2,NULL);


    printf("End of main thread\n");
    
    pthread_exit(NULL);
    return 0;
}