#include<stdio.h>
#include<pthread.h>

void* Thread_Proc(void* ptr)
{
  int iNo = *(int*)ptr;
  printf("Inside Thread %d\n",*(int*)ptr);
  int* result = NULL;
  iNo++;
  result = &iNo;
  pthread_exit(result);
}

int main()
{
  int iret = 0;
  int iNo = 10;
  int *iValue = NULL;
  
  pthread_t TID;
  
  iret = pthread_create(&TID,
                        NULL,
                        Thread_Proc,
                        &iNo);
  
  printf("Thread Created successfully with TID : %ld\n",TID);
  pthread_join(TID,(void **)iValue);
  printf("New Value is : %ls\n",iValue);
  
  printf("End of main thread\n");
  pthread_exit(NULL);
  return 0;
}
