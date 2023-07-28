#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)(int ,int );
    float (*fptrd)(int ,int );
    int iRet = 0, A = 0, B = 0;

    ptr = dlopen("/home/dinesh/Desktop/Assignments/Assignment7/library.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr, "Addition");
    if(fptr == NULL)
    {
        printf("Unable to load function Addition\n");
    }

    printf("Please, enter the first number\n");
    scanf("%d", &A);

    printf("Please, enter the second number\n");
    scanf("%d", &B);
    
    iRet = fptr(A,B);
    printf("Addition is : %d\n", iRet);

    fptr = dlsym(ptr, "Substraction");
    if(fptr == NULL)
    {
        printf("Unable to load function Substraction\n");
    }

    printf("Substraction is : %d\n", fptr(A,B));

    fptr = dlsym(ptr, "Multiplication");
    if(fptr == NULL)
    {
        printf("Unable to load function Multiplication\n");
    }

    printf("Multiplication is : %d\n", fptr(A,B));

    fptrd = dlsym(ptr, "Division");
    if(fptr == NULL)
    {
        printf("Unable to load function Division\n");
    }

    printf("Division is : %f\n", fptrd(A,B));

    return 0;
}