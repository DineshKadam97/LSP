/*
This functions are used to check the current postion from which reading and writing is performed
*/

#include<stdio.h>

int main()
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;

	long pos;

	fp1 = fopen("file.txt","r");
	if(fp1 == NULL)
	{
		printf("Unable toopen the file\n");
	}

	fp2 = fopen("file.txt","a");
	if(fp2 == NULL)
	{
		printf("Unable toopen the file\n");
	}

	// ftell function returns the current file position
	pos = ftell(fp1);
	printf("Current offset if file is opened in read mode is %ld\n",pos);

	pos = ftell(fp2);
	printf("Current offset if file is opened in append mode is %ld\n",pos);

	// We can also use fgetpos function to get same effect
	fgetpos(fp1,&pos);
	// First parameter :	File pointer
	// Second parameter:	Out parameter which receives the output

	printf("Current offset if file is opened in read mode is %ld\n",pos);

	fgetpos(fp2,&pos);
	printf("Current offset if file is opened in read mode is %ld\n",pos);

	// close the opened files
	fclose(fp1);
	fclose(fp2);

	return 0;
}
