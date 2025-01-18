#include<stdio.h>
#include<string.h>
#include<dlfcn.h>
#include<stdbool.h>

int main()
{
    void *ptr = NULL;
    bool (*fptr)(char [], char []);
    bool bRet = false;
    char Arr[25];
    char Brr[25]; 

    ptr = dlopen("/home/dinesh/Desktop/Assignments/Assignment7/library.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr, "FileCompare");
    if(fptr == NULL)
    {
        printf("Unable to load function\n");
        return -1;
    }

    printf("Please, enter the name of the first file\n");
    scanf("%s", Arr);

    printf("Please, enter the name of the first file\n");
    scanf(" %s", Brr);

    bRet = fptr(Arr, Brr);
    if(bRet == true)
    {
        printf("Contents of the file are equal\n");
    }
    else
    {
        printf("Contents of the file are different\n");
    }

}
