# include <stdio.h>
int main(void)
{
    int i, j, k, l, x;  //w代表wushi；e代表ershi；s代表shi
    for(i=0;i<10;i++)
    {
        for(j=0;j<i;j++)
        {
            for(k=0;k<j;k++)
            {
                for(l=0;l<k;l++) 
            
                {
                    printf("%d\n", x);
                }
            }
        }
    }
    return 0;
}
