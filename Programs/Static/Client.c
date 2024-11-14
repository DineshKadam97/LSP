#include<stdio.h>
#include"SharedFile.h"

int main()
{
    int a= 10, b =11, ret = 0;

    ret = Addition(a, b);

    printf("Addition is : %d\n", ret);
    
    return 0;
}


// To compile the client file
// gcc -static Client.c -o Myeyxe SharedFile.a    -static mnje Myexe sobat SharedFile.a chitkav
