// Hard Link

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    char FileName1[30], FileName2[30];
    int iRet = 0;

    printf("Enter the exisiting file name\n");
    scanf("%s", FileName1);

    printf("Enter the name for HardLink\n");
    scanf(" %s", FileName2);

    iRet = link(FileName1, FileName2);

    if(iRet == 0)   //0 indicates success
    {
        printf("HardLink gets created successfully\n");
    }
	
	return 0;
}
