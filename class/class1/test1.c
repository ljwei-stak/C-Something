#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,a=1,b=2,x=3;
    stackempty(s);
    {
        initstack(s);
        push(s,a);
        push(s,b);
        pop(s,x);
        gettop(s,x);
    }
printf("%d",s);    
}

