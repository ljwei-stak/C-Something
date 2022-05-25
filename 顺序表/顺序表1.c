/*****************************/
/**  动态顺序表的各种操作  **/
/*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MaxSize 10

typedef int ElemType;

typedef struct
{
        int *elem;
        int length;
        int listSize;
}sqList;

// 函数功能：初始化一个顺序表
// 参数L：sqList类型的指针
void init(sqList *L)
{
        L->elem = (int *)malloc(MaxSize * sizeof(ElemType));
        if( !L->elem )
                exit(0);

        L->length = 0;
        L->listSize = MaxSize;
}

// 函数功能：向顺序表中插入元素
// 参数L：sqList类型的指针
// 参数i：插入元素的位置
// 参数x：待插入的元素值
void InsertElem(sqList *L, int i, ElemType x)
{
    ElemType *base, *insertPtr, *p;

    if( i<1 || i>L->length+1 )
        exit(0);

    // 如果空间不够放，调用realloc()重新分配空间
    if( L->length >= L->listSize )
    {
        base = (ElemType *)realloc(L->elem, (L->listSize + MaxSize)*sizeof(ElemType));
        L->elem = base;
        L->listSize = L->listSize + MaxSize;
    }

    insertPtr = &(L->elem[i-1]);

    for( p=&(L->elem[L->length-1]); p >= insertPtr; p-- )
    {
        *(p+1) = *p;
    }

    *insertPtr = x;
    L->length++;

}

// 在顺序表中删除元素
// 参数L：sqList类型的指针
// 参数i：待删除的元素位置
void DelElem(sqList *L, int i)
{
    ElemType *delItem, *q;

    if( i<1 || i>L->length )
        exit(0);

    delItem = &(L->elem[i-1]);
    q = L->elem + L->length - 1;

    for( ++delItem; delItem <= q; ++delItem )
    {
        *(delItem-1) = *delItem;
    }

    L->length--;
}

int main()
{
    sqList l;
    int i;

    init( &l );
    printf("当前表的数据个数是：%d\n", l.length);
    printf("当前表的组大容量是：%d\n", l.listSize);

    printf("\n向顺序表插入15个元素。。。\n");
    for( i=0; i < 15; i++ )
    {
        InsertElem( &l, i+1, i+1 );
    }
    printf("表中的内容是：");
    for( i=0; i < l.length; i++ )
    {
        printf("%d ", l.elem[i]);
    }
    printf("\n当前表的数据个数是：%d", l.length);
    printf("\n当前表的组大容量是：%d", l.listSize);

    printf("\n\n删除第五个元素。。。\n");
    DelElem( &l, 5 );

    printf("表中的内容是：");
    for( i=0; i < l.length; i++ )
    {
        printf("%d ", l.elem[i]);
    }
    printf("\n当前表的数据个数是：%d", l.length);
    printf("\n当前表的组大容量是：%d\n", l.listSize);

    return 0;
}
