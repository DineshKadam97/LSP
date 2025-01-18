#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

int Counter = 0;

void * ThreadProc(void *ptr)
{
  int i = 0;
  Counter++;
  printf("Thread executed with Counter : %d\n",Counter);
  for(i = 0; i < 0xFFFFFFFF; i++);
  printf("Thread completed with Counter : %d\n",Counter);
  pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int ret = 0;

    ret = pthread_create(&TID1,            // Address of pthread_attr_t structure object
                          NULL,           // Thread attributes
                          ThreadProc,     // Address of callback function
                          NULL);     // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    ret = pthread_create(&TID2,            // Address of pthread_attr_t structure object
                          NULL,           // Thread attributes
                          ThreadProc,     // Address of callback function
                          NULL);     // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    
    pthread_join(TID1,NULL); //i
    pthread_join(TID2,NULL);

    printf("End of main thread\n");
    return 0;
}