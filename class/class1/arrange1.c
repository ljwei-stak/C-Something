#include <stdio.h>
#include <stdlib.h>
#define num 10

int main()
{
    int s[num];
    int i,sum =0;
    for (i=0;i<10;i++)
    {
        printf("�������%iλͬѧ�ĳɼ��� ",i+1);
        scanf("%d",&s[i]);
        sum+=s[i];
    }
    printf("�ɼ�¼����ϣ��ôο��Ե�ƽ�����ǣ�%.2f\n", (double)sum / num);
}
