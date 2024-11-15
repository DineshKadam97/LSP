// This program demonstates temorary file creation

#include<stdio.h>

int main()
{
FILE *fp;

fp = tmpfile();  //use and throw tissue

if(fp == NULL)
{
	printf("Unable to create temporary file.\n");
}

// Now we can use this fp for further file operation

return 0;
}
