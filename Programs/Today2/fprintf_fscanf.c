/*
	This program demonstate formatted input output from file by using fprint() & fscanf()
*/

#include<stdio.h>

int main()
{
	FILE *fp = NULL;
	char str[]="New string";
	char ch;

	// open the file
	fp = fopen("file.txt","r+");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
	}

	// fprinf is similar as printf but insted of writing the contents on STDOUT it writes the contents in file.
	// It returns no of characters successfully written in file.

	fprintf(fp,"\t%s\n",str);

	// fscanf is similar as scanf but insted of reading the contents from STDIN it reads the contents from file.
	// It returns no of characters successfully read from file.

	fscanf(fp,"%c",&ch);
	printf("Character read by fscanf is : %c\n",ch);

	return 0;
}
