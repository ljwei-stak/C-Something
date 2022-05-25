#include"stdio.h"
#include"dos.h"
#include"graphics.h"

typedef struct PaletteColor
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
}PalColor,*PalColor_p;

PalColor_p GetPalColor(int index)   /*��ȡ���Ϊindex�ĵ�ɫ��Ĵ�������ɫ��Ϣ*/
{
    PalColor_p color;
    outp(0x3c6,0xff);
    outp(0x3c7,index);
    color->red=inp(0x3c9);
    color->green=inp(0x3c9);
    color->blue=inp(0x3c9);
    return color;
}

void SetPalColor(int index, PalColor_p color) /*�������Ϊindex�ĵ�ɫ��Ĵ�����ɫ*/
{
    outp(0x3c6,0xff);
    outp(0x3c8,index);
    outp(0x3c9,color->red);
    outp(0x3c9,color->green);
    outp(0x3c9,color->blue);
}

main()
{
    int i,j,index;
    int gd=DETECT,gm;
    PalColor *old_color,color;   /*����old_color���ڱ���ԭ�Ĵ�����ɫ��Ϣ*/
    initgraph(&gd,&gm,"");
    index=1;                 /*���ý�Ҫʹ�õĵ�ɫ��Ĵ������Ϊ1��*/
    setcolor(15);
    circle(300,200,50);
    setfillstyle(1,index);
    /*ʹ��1�ŵ�ɫ��Ĵ����ڴ�ŵ���ɫ����ʼΪ��ɫ�������Բ*/
    floodfill(300,200,15);
    old_color=GetPalColor(index); /*����1�żĴ���������ɫ��Ϣ*/
    color.red=color.green=color.blue=0; /*����ԭɫ����ʼ��Ϊ0*/
    getch();
    for(i=0;i<63;i++)
    {
        /*ʹ��ԭɫ��ֵ���μ�1*/
        color.red+=1;   
        color.green+=0;
        color.blue+=1;
        SetPalColor(1,&color); /*������colorָ�����µ���ɫ��1�żĴ�����*/
        for(j=0;j<10;j++)     /*��ʱ*/
        delay(5000);
    }
    SetPalColor(1,old_color);
    /*��Բ�ڵ���ɫ�ﵽ����ʱ���������old_color�������ɫ*/
    getch();
}
