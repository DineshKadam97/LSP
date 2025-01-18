#include"Prime.h"

bool CheckPrime(int iNo)
{
    int iCnt = 0;

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
