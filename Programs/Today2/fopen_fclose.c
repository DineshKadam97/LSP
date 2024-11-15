/*

	- fopen() is a function from C standard library. which is declared in stdio.h file.
	- This function not directly operate on file descriptor. It uses there own unique
	  identifier called as file pointer. This file pointer maps to the file descriptor.
	- In standard I/O opened file is called as stream which can be opened for reading or
	  writing.

	- Structure which is used to represent open file is in stdio.h called as FILE.
	  which is declared as

	typedef struct
	{
		short level;		// fill/empty buffer level
		unsigned flags;		// file status flag
		char fd;		// file decriptor
		unsigned char hold;	// ungetc character if no buffer
		short bsize;		// buffer size
		unsigned char *buffer;	// data transfer buffer
		unsigned char *curp;	// current active pointer
		unsigned int istemp;	// Temporary file indicator
		short token;		// used for validity checking
	}FILE;

	When we open any file this structure gets filled with the appropriate contents.

*/

#include<stdio.h>

int main()
{
	FILE *fp;

	fp = fopen("file.txt","r");
	// First parameter :	File name to be opened
	// Second parameter :	Mode in which file to be open	

	/*
		Mode in which file can be open :

		r :	Read mode
		w :	Writing mode. If file exist it gets truncated otherwise new created
		a :	Append mode
		rb :	Binary read mode
		rw :	Binary write mode
		ab :	Binary append mode	
		r+ :	Open existing file for reading and writing
		w+ : 	Open existing file for reading and writing. If not existing then new file is created
		a+ :	Open for reading and appending	
	*/	

	if(fp == NULL)
	{
		printf("Unable to open file\n");
	}
	printf("\nFile Opened.\n");
	// Close the file
	fclose(fp);
	printf("File Closed.\n");
	// It is used to close all opened files
	fcloseall();
	printf("All files are closed\n");
	return 0;
}
