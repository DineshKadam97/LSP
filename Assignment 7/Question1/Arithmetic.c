#include<stdio.h>
#include"Arithmetic.h"

int Addition(int iNo1,int iNo2)
{
    int iAns = 0;
    iAns = iNo1 + iNo2;

    return iAns;
}

int Substraction(int iNo1,int iNo2)
{
    int iAns = 0;
    iAns = iNo1 - iNo2;

    return iAns;
}

int Multiplication(int iNo1,int iNo2)
{
    int iAns = 0;
    iAns = iNo1 * iNo2;

    return iAns;
}

float Division(int iNo1,int iNo2)
{
    float iAns = 0.0f;
    iAns = (float)iNo1 / (float)iNo2;

    return iAns;
}