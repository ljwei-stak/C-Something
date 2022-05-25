#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;
    {
      i=f(3);
   printf("%d\n",i);
    }  
   return 0;
}
f(int n)
{
   return((n<=0)?n:f(n-1)+f(n-2)); 
}