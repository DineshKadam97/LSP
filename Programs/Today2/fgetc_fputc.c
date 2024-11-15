/*

This functions are used to read or write the contents into the file in character by character manner

*/

#include<stdio.h>

int main()
{

	FILE *fp1 = NULL;
	FILE *fp2 = NULL;

	char str[] ="Hello world";
	char ch;
	int i = 0;

	// Open the file in read mode
	fp1 = fopen("file.txt","r");
	if(fp1 == NULL)
	{
		printf("Unable to open file\n");
	}

	// fgetc function read single single character from the file till End of file occur
	printf("File contents are\n");
	while((ch = fgetc(fp1))!=EOF)
	{
		printf("%c",ch);
	}

	// Close the opened file
	fclose(fp1);

	// Open the file in append mode
	fp2 = fopen("file.txt","a");
	if(fp2 == NULL)
	{
		printf("Unable to open file\n");
	}

	printf("Writing contents into the file\n");
	while(str[i]!= '\0')
	{
		fputc(str[i],fp2);
		// First patrameter :	Character to be write in file
		// Second parameter :	File pointer	
		i++;
	}

	// Close the opened file
	fclose(fp2);

	return 0;
}
