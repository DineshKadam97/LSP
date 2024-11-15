/*
fseek function is used to change the file position which is used for further reading or writing.
*/

#include<stdio.h>

int main()
{
	FILE *fp = NULL;
	int ret;
	char ch;

	fp = fopen("file.txt","r+");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
	}

	// Print the contents of file
	printf("File contents before fseek are\n");
	while((ch = fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}

	ret = fseek(fp,5,SEEK_SET);
	// First parameter :	File pointer
	// Second parameter :	Number of bytes to seek (It can be negative also)
	// Third parameter :	It indecates from where we have to seek
	// Third parameter is as follows :
	// SEEK_SET :	Seek from begining of the file (0)
	// SEEK_CUR :	Seek from current position (1)
	// SEEK_END :	Seek from end of the file (2)

	if(ret != 0)
	{
		printf("Unable to seek\n");
	}

	// Write character 'z' at the new position
	fputc('z',fp);

	printf("\n\nFile contents before fseek are\n");

	// Set the file position to the begining
	fseek(fp,0,SEEK_SET);

	// The above effect can be achived through the function rewind
	// rewind() function sets file position indecator to start of the file

	rewind(fp);

	while((ch = fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	return 0;
}
