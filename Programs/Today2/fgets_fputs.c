/*
	This program demonstate how to read line or how to write line into the file
*/

#include<stdio.h>

int main()
{

	FILE *fp;
	char str[50];
	char *p;
	int ret;

	// open the file in read mode
	fp = fopen("file.txt","r");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
		return -1;
	}

	// fgets function read the string from file till new line character occurs or length satisfies
	p = fgets(str,10,fp);
	// First parameter :	Array in which data is to be read
	// Second parameter :	Number of character to read
	// Third parameter :	File pointer

	// If there is some error then it returns NULL
	if(p == NULL)
	{
		printf("Error in fgets\n");
		return -1;
	}


	printf("Contents read by fgets are :\n%s",str);

	fclose(fp);

	// open the file in write mode
	fp = fopen("file.txt","w");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
		return -1;
	}

	ret = fputs("New line inserted in file",fp);
	// First parameter :	String which is to be written in file
	// Second parameter :	File pointer

	// IF therere is some error it reaturns EOF
	if(ret == EOF)
	{
		printf("Unable to write contents in file\n");
		return -1;
	}

	return 0;	
}
