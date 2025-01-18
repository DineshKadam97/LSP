#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include"FileInfo.h"

void DisplayInfo(char *str)
{
    struct stat sobj;

    stat(str, &sobj);

    printf("File Name is : %s\n", str);
    printf("File Size is : %ld\n", sobj.st_size);
    printf("Inode Number is : %ld\n", sobj.st_ino);
    printf("Number of links : %ld \n", sobj.st_nlink);
    printf("File System Number : %ld\n", sobj.st_dev);   // Device ID
    printf("Number of Blocks : %ld\n", sobj.st_blocks);
    printf("User ID is : %u\n", sobj.st_uid);
    printf("Group ID is : %u\n", sobj.st_gid);
    printf("Block Size : %lu\n", sobj.st_blksize);
    printf("Last Acces Time : %ld\n", sobj.st_atime);
    printf("Last Modification Time : %lu\n", sobj.st_mtime);
    printf("Last status change Time : %ld\n", sobj.st_ctime);

}