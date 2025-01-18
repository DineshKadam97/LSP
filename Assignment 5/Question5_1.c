///////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which writes structure in a file. Structure should 
//                     contain information of student.
//
/////////////////////////////////////////////////////////////////////////////////////////////

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

   sobj.RollNo = 11;
   strcpy(sobj.Sname, "Dinesh");
   sobj.Marks = 88.99f;
   sobj.Age = 25;

   printf("Enter the file name : \n");
   scanf("%s", Fname);

   fd = creat(Fname, 0777);
   if(fd == -1)
   {
     printf("Unable to create file\n");
   }

   write(fd, &sobj, sizeof(sobj));
   
   printf("Structure is written in the file succesfuly\n");
   
   close(fd);
   
   return 0;
}
