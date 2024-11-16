//Problems on numbers using multithreading
//even/odd, displayfactors, sumfactors, checkperfect, checkPrime, CalculateFactor, DisplayFactorial, CountPower

#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
typedef unsigned long int ULONG;

void* EvenOdd(void* ptr)
{
  int iNo = *(int*)ptr;
  
  if(iNo % 2 == 0)
  {
    printf("Number is even\n");
  }
  else
  {
    printf("Number is odd\n");
  }
  
  pthread_exit(NULL);
}

void* DisplayFactors(void* ptr)
{
  int iNo = *(int*)ptr;
  printf("The factors are\n");
  
  for(int i = 1; i <= iNo/2; i++)
  {
    if(iNo % i == 0)
    {
      printf("%d\n",i);
    }
  }
  
  pthread_exit(NULL);
}

void* SumFactors(void* ptr)
{
  int iNo = *(int*)ptr;
  int iSum = 0;
  
  for(int i = 1; i <= iNo/2; i++)
  {
    if(iNo % i == 0)
    {
      iSum = iSum + i;
    }
  }

  int* Result = malloc(sizeof(int));
  *Result = iSum;
  pthread_exit(Result);
}

void* CheckPerfect(void* ptr)
{
  int iNo = *(int*)ptr;
  int SumF = 0;
  
  for(int i = 1; i <= iNo/2; i++)
  {
    if(iNo % i == 0)
    {
      SumF = SumF + i;
    }
  }
  
  if(SumF == iNo)
  {
    printf("Number id perfect\n");
  }
  else
  {
    printf("Number is not perfect\n");
  }
  
  pthread_exit(NULL);
}

void* CheckPrime(void* ptr)
{
  int iNo = *(int*)ptr;
  if (iNo < 2)
  {
    printf("Number is not prime\n");
    pthread_exit(NULL);
  }

  for (int i = 2; i <= iNo / 2; i++)
  {
    if (iNo % i == 0)
    {
      printf("Number is not prime\n");
      pthread_exit(NULL);
    }
  }

  printf("Number is prime\n");
  pthread_exit(NULL);
}

void* CalculatePower(void* ptr)
{
  int iNo = *(int*)ptr;
  int SumF = 0;
  
  ULONG iResult = 1;
  
  for(int i = 1; i <= 3; i++)
  {
     iResult = iResult * iNo;
  }
  
  ULONG* result = (ULONG*)malloc(sizeof(ULONG));
  *result = iResult;
  
  pthread_exit(result);
}

void* DisplayFactorial(void* ptr)
{
  int iNo = *(int*)ptr;
  int SumF = 0;
  
  ULONG iResult = 1;
  
  for(int i = iNo; i >= 1; i--)
  {
     iResult = i * iResult;
  }
  
  printf("Factorial : %lu\n",iResult);
  
  ULONG* result = malloc(sizeof(ULONG));
  *result = iResult;
  
  pthread_exit(result);
}



int main()
{
  int iNo = 35;
  
  pthread_t TID[7];
  void* Arr[7] = {EvenOdd, DisplayFactors, SumFactors, CheckPerfect, CheckPrime, CalculatePower,DisplayFactorial};
  
  int* Value = NULL;
  
  for(int i = 0; i < 7; i++)
  {
    pthread_create(&TID[i],
                   NULL,
                   Arr[i],
                   &iNo);
  }
  
  for(int i = 0; i < 7; i++)
  {
     if(i == 2 || i == 5 || i == 6)
     {
        pthread_join(TID[i],(void**)&Value);
        if(i == 6)
        {
           printf("Result : %lu\n",*(ULONG*)Value);
        }
        else
        {
          printf("Result : %d\n",*Value);
        }
        
        free(Value);
     }
     else
     {
       pthread_join(TID[i],NULL);
     }
  }
  return 0;
}
