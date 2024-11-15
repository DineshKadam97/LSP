#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main(void)
{
	int fd1;
	int ret;
	char buff[]="New data";

	// If file is opened in read mode
	fd1 = open("New1.txt",O_RDWR);
	if(fd1 == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}
		
	ret = write(fd1,buff,sizeof(buff)-1);
	if(ret != 8)
	{
		printf("Unable to write in file\n");
		return -1;
	}
	printf("\nContents written inside the file\n");

	//The sync function simply queues all the modified block buffers for 
	//writing and returns; it does not wait for the disk writes to take place.
	sync();  // Sagle Buffer line madhe lavto

	// The function fsync refers only to a single file, specified by the 
	// file descriptor filedes, and waits for the disk writes to complete 
	// before returning.
	fsync(fd1);  //jicha fd tila line madhe lavto aani data lihi parynt vat pahto

	// The fdatasync function is similar to fsync, but it affects only the 
	// data portions of a file. With fsync, the file's attributes(INODE) are 
	// also updated synchronously.
	fdatasync(fd1);   

	return 0;
}
