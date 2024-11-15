#include <fcntl.h>
#include<stdio.h>

char buf1[] = "First line";
char buf2[] = "Last line";

int main(void)
{
	int fd;
	int offset;

	fd = open("new.txt",O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}

	// File is opened in read or write mode current file offset
	// is always zero
	// Means we open a file which is already existing and we write something
	// in that file then data gets overwritten
	
	// To change the current file offset we can use lseek function	

	offset = lseek(fd,0,SEEK_SET);
	printf("offset is %d\n",offset);

	// SEEK_SET means staring offset of file
	// SEEK_CUR means current offset of file
	// SEEK_END means last byte offset of file

	// We can change the file offset 50 bytes from the starting position by 

	offset = lseek(fd,50,SEEK_SET);
	printf("Now current offset is %d\n",offset);

	// We can also move the current byte offset in backward direction

	offset = lseek(fd,-20,SEEK_CUR);
	printf("After backward traversal offset is %d\n",offset);

	// To check the last byte offset of the file we can call lseek function as

	offset = lseek(fd,0,SEEK_END);
	printf("Last byte offset is %d\n",offset);

	return 0;
}