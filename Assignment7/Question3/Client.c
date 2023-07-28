#include<stdio.h>
#include<dlfcn.h>
#include<stdbool.h>

int main()
{
    void *ptr = NULL;
    bool (*fptr)(int);

    int iNo = 0;
    bool bRet = 0;

    ptr = dlopen("/home/dinesh/Desktop/Assignments/Assignment7/library1.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr, "CheckPrime");
    if(fptr == NULL)
    {
        printf("Unable to load function Checkprime\n");
        return -1;
    }
    
    printf("Please, enter the number: \n");
    scanf("%d", &iNo);

    bRet = fptr(iNo);
    if(bRet == true)
    {
        printf("%d is Prime number\n", iNo);
    }
    else
    {
        printf("%d is not a Prime number\n", iNo);
    }

    ptr = dlopen("/home/dinesh/Desktop/Assignments/Assignment7/library2.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
    }
      

    fptr = dlsym(ptr, "CheckPerfect");
    if(fptr == NULL)
    {
        printf("Unable to load function CheckPerfect\n");
        return -1;
    }

    bRet = fptr(iNo);
    if(bRet == true)
    {
        printf("%d is a Perfect number\n", iNo);
    }
    else
    {
        printf("%d is not a Perfect number\n", iNo);
    }

    return 0;

}
