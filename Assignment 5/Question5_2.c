/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name from user which contains information
//                     of the student, we have to read all the contents from that file.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#pragma pack(1)
struct Student
{
    char Sname[20];
    int RollNo;
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
   int fd = 0;
   char Fname[20];

   struct Student sobj;

   printf("Enter the file name : \n");
   scanf("%s", Fname);

   fd = open(Fname, O_RDONLY);
   if(fd == -1)
   {
     printf("Unable to create file\n");
   }
   
   read(fd, &sobj, sizeof(sobj));
   
   printf("Information about the student is : \n");
   
   printf("Name : %s\n", sobj.Sname);
   printf("Roll No : %d\n", sobj.RollNo);
   printf("Age : %d\n", sobj.Age);
   printf("Marks : %f\n", sobj.Marks);

   close(fd);

   return 0;
}
