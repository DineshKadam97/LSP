//Program to demostrate startup and exit using #pragma.
#include<stdio.h>
#include<stdlib.h>
void fun();
void sun() ;

#pragma startup fun   //#pragma startup chya pudhe aapan function ch naav deto, brackets() nahi 

#pragma exit sun

void fun()
{
  printf("\nIn fun");   //IO(input output) specific kahi lihu naka
  exit(0);
}

void sun()
{
  printf("\nIn sun");
}

int main()
{
printf("\nIn main");
return 0;
}


