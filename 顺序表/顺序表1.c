/*****************************/
/**  ��̬˳���ĸ��ֲ���  **/
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

// �������ܣ���ʼ��һ��˳���
// ����L��sqList���͵�ָ��
void init(sqList *L)
{
        L->elem = (int *)malloc(MaxSize * sizeof(ElemType));
        if( !L->elem )
                exit(0);

        L->length = 0;
        L->listSize = MaxSize;
}

// �������ܣ���˳����в���Ԫ��
// ����L��sqList���͵�ָ��
// ����i������Ԫ�ص�λ��
// ����x���������Ԫ��ֵ
void InsertElem(sqList *L, int i, ElemType x)
{
    ElemType *base, *insertPtr, *p;

    if( i<1 || i>L->length+1 )
        exit(0);

    // ����ռ䲻���ţ�����realloc()���·���ռ�
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

// ��˳�����ɾ��Ԫ��
// ����L��sqList���͵�ָ��
// ����i����ɾ����Ԫ��λ��
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
    printf("��ǰ������ݸ����ǣ�%d\n", l.length);
    printf("��ǰ�����������ǣ�%d\n", l.listSize);

    printf("\n��˳������15��Ԫ�ء�����\n");
    for( i=0; i < 15; i++ )
    {
        InsertElem( &l, i+1, i+1 );
    }
    printf("���е������ǣ�");
    for( i=0; i < l.length; i++ )
    {
        printf("%d ", l.elem[i]);
    }
    printf("\n��ǰ������ݸ����ǣ�%d", l.length);
    printf("\n��ǰ�����������ǣ�%d", l.listSize);

    printf("\n\nɾ�������Ԫ�ء�����\n");
    DelElem( &l, 5 );

    printf("���е������ǣ�");
    for( i=0; i < l.length; i++ )
    {
        printf("%d ", l.elem[i]);
    }
    printf("\n��ǰ������ݸ����ǣ�%d", l.length);
    printf("\n��ǰ�����������ǣ�%d\n", l.listSize);

    return 0;
}
