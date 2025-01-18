#include"Perfect.h"

bool CheckPerfect(int iNo)
{
    int iCnt = 0;
    int iSum = 0;

    for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
    {
       if(iNo % iCnt == 0)
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