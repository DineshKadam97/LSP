#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);  //stat function aahe, rikama form pathvne,

    printf("File name : %s\n",argv[1]);
    printf("File size is : %d\n",sobj.st_size);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Inode number : %d\n",sobj.st_ino);
    printf("File system number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);

    return 0;
}

//  dev_t     st_dev;     /* ID of device containing file */
//     ino_t     st_ino;     /* Inode number */
//     mode_t    st_mode;    /* File type and mode (permissions) */
//     nlink_t   st_nlink;   /* Number of hard links */
//     uid_t     st_uid;     /* User ID of owner */
//     gid_t     st_gid;     /* Group ID of owner */
//     dev_t     st_rdev;    /* Device ID (if special file) */
//     off_t     st_size;    /* Total size, in bytes */
//     blksize_t st_blksize; /* Block size for filesystem I/O */
//     blkcnt_t  st_blocks;  /* Number of 512B blocks allocated */

//     /* Since Linux 2.6, the kernel supports nanosecond precision for the following timestamp fields.
//        For backward compatibility, these are also available as st_atime, st_mtime, and st_ctime. */
