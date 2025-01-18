////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates static library which contains file name from user and which
//                     displays the information of that file.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include"FileInfo.h"

int main()
{
    char Arr[30];

    printf("Please, enter the name of the file\n");
    scanf("%s", Arr);

    DisplayInfo(Arr);

    return 0;
}
