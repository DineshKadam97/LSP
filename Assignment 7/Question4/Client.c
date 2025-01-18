/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates shared library which internally loads other shared library.
//                     The inner shared library provides function to calculate factorial of the number.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dlfcn.h>
typedef unsigned long int ULONG;

int main()
{
    void *ptr1 = NULL;
    int* (*fptr1)();
    void *ptr2 = NULL;
    ULONG (*fptr2)(int);
    ULONG Ret = 0;
    int iNo = 0;

    ptr1 = dlopen("/home/dinesh/Desktop/Assignments/Assignment7/outerlibrary.so", RTLD_LAZY);
    if(ptr1 == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr1 = dlsym(ptr1, "OpenInnerFile");
    if(fptr1 == NULL)
    {
        printf("Unable to open file\n");
    }

    ptr2 = fptr1();

    fptr2 = dlsym(ptr2, "Factorial");
    if(fptr2 == NULL)
    {
        printf("Unable to load function Factorial\n");
    }

    printf("Please, enter the number\n");
    scanf("%d", &iNo);

    Ret = fptr2(iNo);

    printf("Factorial of %d is : %lu\n", iNo, Ret);

    return 0;
}
