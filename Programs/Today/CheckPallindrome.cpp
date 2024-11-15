#include<iostream>
using namespace std;

class String
{
    private:
       char *str;

    public:
      String(char *X)
      {
          str = X;
      }

      void CheckPallindrome()
      {
         char *start = NULL;
         char *end = NULL;

         start = str;
         end = str;


         while(*end != '\0')
         {
            end++;
         }
         end--;

         while(start < end)
         {
            if(*start != *end)
            {
              break
            }
            start++;
            end--;
         }
         
         if(start < end)
         {
           return false;
         }
         else
         {
           return true;    
         }
};

int main()
{
    char Arr[25];
    char Brr[25];

    printf("Please, enter the string \n");
    scanf("%[^'\n']s", Arr);

    String sobj(Arr);

    sobj.CheckPallindrome();

    printf("Reverse String is %s \n", Arr);

    return 0;
}
