#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
  void *ptr = NULL;
  void(*fptr)();
  
  ptr = dlopen("/home/dinesh/Desktop/LSP/Dynamic/library.so",RTLD_LAZY);
  if(ptr == NULL)
  {
    printf("Unable to load library\n");
    return -1;
  }
  
  fptr = dlsym(ptr,"Display");
  if(fptr == NULL)
  {
    printf("Unable to load function\n");
    return -1;
  }
  
  fptr();
  
  return 0;
}
   

// TO create .o file
// gcc -c -FPIC Sharedfile.c

// To create .so file
// gcc -shared -o library.so SharedFile.o
