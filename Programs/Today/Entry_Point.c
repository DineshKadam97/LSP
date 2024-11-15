#include<stdio.h>
#include<stdlib.h>
#pragma startup(New_Main)

int New_Main()
{
	printf("Inside New entry point function\n");
	exit(0);
}
int main()
{
	printf("Inside main\n");
	return 0;
}