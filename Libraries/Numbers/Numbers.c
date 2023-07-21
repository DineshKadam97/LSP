#include<stdio.h>
#include<stdbool.h>
#include"Numbers.h"

bool CheckEven(int iNo)
{
    if(iNo % 2 == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool CheckOdd(int iNo)
{
    if(iNo % 2 != 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool CheckPrime(int iNo)
{
    int iCnt = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 2; iCnt <= (iNo/2); iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            break;
        }
    }

    if(iCnt == (iNo/2)+1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DisplayFactors(int iNo)
{
    int iCnt = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }
    
    for(iCnt = 1; iCnt <= iNo/2; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            printf("%d\t", iCnt);
        }
    }
    printf("\n");
}

int FactorsSum(int iNo)
{
    int iCnt = 0;
    int iSum = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt <= iNo/2; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iSum = iSum + iCnt;
        }
    }

    return iSum;
}

float FactorsAvg(int iNo)
{
    int iCnt = 0;
    int iCount = 0;
    int iSum = 0;
    float fAvg = 0.0f;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt <= iNo/2; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iSum = iSum + iCnt;
            iCount++;
        }
    }

    fAvg = (float)iSum/(float)iCount;

    return fAvg;
}

bool CheckPerfect(int iNo)
{
    int iCnt = 0;
    int iSum = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt <= iNo/2; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iSum = iSum + iCnt;
        }

        if(iSum > iNo)
        {
            break;
        }
    }

    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned long int Factorial(int iNo)
{
    int iCnt = 0;
    unsigned long int iFact = 1;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        iFact = iFact * iCnt;
    }

    return iFact;
}

unsigned long int Exponent(int iBase, int iPower)
{
    int iCnt = 0;
    unsigned long int iExponent = 1;

    if(iBase < 0)
    {
        iBase = -iBase;
    }

    if(iPower < 0)
    {
        iPower = -iPower;
    }

    for(iCnt = 1; iCnt <= iPower; iCnt++)
    {
        iExponent = iExponent * iBase;
    }

    return iExponent;
}
