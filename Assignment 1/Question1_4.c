////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name from user and print all the
//                     information of that file.
//
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    struct stat sobj;

    stat(argv[1], &sobj);

    printf("File name is : %s\n", argv[1]);
    printf("Inode number is : %lu\n", sobj.st_ino);
    printf("Type of the file is : %u\n", sobj.st_mode);
    printf("Size of the file is : %lu\n", sobj.st_size);
    printf("Number of links : %lu\n", sobj.st_nlink);
    printf("Device ID is : %lu\n", sobj.st_dev);
    printf("User ID is : %u\n", sobj.st_uid);
    printf("Group ID is : %u\n", sobj.st_gid);
    printf("Block Size : %lu\n", sobj.st_blksize);
    printf("Number of Blocks are : %lu\n", sobj.st_blocks);
    printf("Last Acces Time : %ld\n", sobj.st_atime);
    printf("Last Modification Time : %lu\n", sobj.st_mtime);
    printf("Last status change Time : %ld\n", sobj.st_ctime);

    return 0;
}
