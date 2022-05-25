#include "time.h"
#include "stdio.h"
#include "graphics.h"
 /*

 9    ը��
 0    �ո�
 1~8  Ϊ ��Χ��ը������Ϊ ��Χ��ը����Ŀ
  15  ���
  10 11 ɨ���Ѿ��ݹ�ĵط�

 */

#define start_x 90
#define start_y 90
#define LEN 10
#define UP   0x4800
#define DOWN  0x5000
#define LEFT   0x4b00
#define RIGHT 0x4d00
#define ESC   0x11b
#define BS    0x3920
#define X    0x2d78
#define N 30
#define TIMES  N*N/7
unsigned char map[N+1][N+1]; /* ΪʲôҪ��Ƴ� n+1������

                                ��ΪҪ����ÿ������
    ���������ᷢ��                         ��Χ�ĵ�����Ŀ �ȵĻ�
                             ÿ�λ�Ҫ���� Խ�������
            111                 �����⸴�ӻ�   ����Ҫ�Ƕ��һ�� ���Ҹ�ֵΪ0 ����around�ĺ�����ʽ���ܼ����
            101
            111
            0�������� ������Χ���ӵ� Խ������

  */
            int randmap();
int rand_2(int max,int min);   /*

������غ���ֵ �����α��� ���б� �ı�ʾ����
*/
void around();   /* */
void pri_num();
int sao(int row,int line); /*  ���ĵط�

���ݶ�������ǰ��ݹ� ������ ����Կ��� ������� ��ʵ�����Ǹ��ķ���

 */
 /*
 ����Ϊ ��ͼ����

 */
 void init(int color);
 void drawrec(int row,int line,int color);
 void drawmap(int kcolor,int color);
 void move();
 void drawmov(int row,int line,int color);
 void drawtxt(int row,int line,int color,char *str);
 void sign(int row,int line,int color);
 void main(){
  int key;
  int row=1,line=1;
  int unlife=0;
  int sign_n=0;
  int havesign=0;
  srand(time(NULL));
  randmap();
  around();

  init(BLACK);
  drawmap(BLUE,WHITE);




/*sao(row,line); */
  while(!unlife)
  {


    key=bioskey(0);
    switch(key)
    {
/*
�����������Ǵ�1��ʼ ��  N-1 ������

*/
case UP:if((row-1)>=1)
{
 drawmov(row,line,BLUE);
 row--;
 drawmov(row,line,RED);

}break;
case DOWN:if((row+1)<=(N-1))
{
 drawmov(row,line,BLUE);
 row++;
 drawmov(row,line,RED);

}break;
case RIGHT:if((line+1)<=(N-1))
{
 drawmov(row,line,BLUE);
 line++;
 drawmov(row,line,RED);

}break;
case LEFT:if((line-1)>=1)
{
 drawmov(row,line,BLUE);
 line--;
 drawmov(row,line,RED);

}break;
case ESC:closegraph();exit(0); break;
case BS:if(map[row][line]<=8&&map[row][line]>=0)
{

  sao(row,line);

}
else if(map[row][line]==9)
{

                  unlife=1;/*  ���� */
  cleardevice();
  setbkcolor(WHITE);
  setcolor(RED);
  outtextxy(300,200,"You|are|over");

}

break;
case X:if(map[row][line]>=0&&map[row][line]<=9)
{
 sign(row,line,YELLOW);
                    /*

                    ����� ÿ�� ֻҪ�����Ѿ���������
                    ����Ա��
                    �����ǵĵط�Ϊ ը�� ��֤���ҵ�����Ŀ+1
                    ��� �ҵ�����Ŀ�Ѿ���ը����Ŀ
                     �ж�Ϊʤ��
                    */
                     havesign+=1;

                     if(map[row][line]==9)
                     {

                      sign_n+=1;
                      if(sign_n==TIMES)
                      {

                        cleardevice();
                        setcolor(YELLOW);
                        outtextxy(300,200,"You Win This Game");
                        getch();
                        closegraph();
                        exit(0);
                      }


                    }
                    if(havesign==TIMES&&sign_n<TIMES)
                    {
                     unlife=1;


                   }
                   map[row][line]=15;
                 }   break;
                 default :break;

               }
             }
             getch();
             closegraph();
           }
           void around()
           {
            int row=1;
            int line=0;
            int n=0;
            for(;row<N;row++)


              for(line=1;line<N;line++)
              { 
                n=0;
                if(map[row][line]==0)
                {
       /*
       ΪʲôҪ���� 9
       9 ����ը��
       0
       9/9=1
       0/9=0
       ���Կ�����������
       */
       n+=map[row-1][line-1]/9;
       n+=map[row-1][line+1]/9;
       n+=map[row+1][line+1]/9;
       n+=map[row+1][line-1]/9;
       n+=map[row-1][line]/9;
       n+=map[row+1][line]/9;
       n+=map[row][line+1]/9;
       n+=map[row][line-1]/9;
       map[row][line]=n;
     }
     
   }
   
 }


 int randmap()
 {
  int times;
  int row_;
  int line_;
  int ans;
  for(times=0;times<TIMES;times++)
  {
    ans=rand_2((N+1)*(N+1)-1,0);
row_=ans/(N+1);         /*


*/
line_=ans%(N+1);
if (map[row_][line_]!=9&&(row_!=0&&line_!=0&&row_!=N&&line_!=N)) {

  map[row_][line_]=9;

}
else
{
  times--;
}
}
for(row_=0;row_<(N+1);row_++)
  for(line_=0;line_<(N+1);line_++)
  {
    if (map[row_][line_]!=9) {
      map[row_][line_]=0;
    }
  }
}
int rand_2(int max,int min)
{

  return rand()%(max-min+1)+min;
}

void pri_num()
{
  int row;
  int line;
  for(row=1;row<N;row++)
  {
   printf("\n\n\t\t\t");
   for(line=1;line<N;line++)
   {
    printf("%3d",map[row][line]);
  }

}
}

int sao(int row,int line)
{
  char str[2];
  str[1]='\0';
  if(row==0||line==N||row==N||line==0)
  {
                  /*

                  �������緵��
                  */
                  return NULL;
                }
                else if (map[row][line]==0) {
                  drawrec(row,line,BLUE);
                  map[row][line]=10;
 /* sao(row-1,line-1);
    sao(row-1,line+1);
    sao(row+1,line+1);
     sao(row+1,line-1);  */
    sao(row-1,line);
    sao(row+1,line);
    sao(row,line+1);
    sao(row,line-1);
    
  }
  else if (map[row][line]>=1&&map[row][line]<=8) {
    drawrec(row,line,GREEN);
str[0]=map[row][line]+'a'-1;      /*

����ը����Χ�ĸ���fanhui
*/
drawtxt(row,line,RED,str);
map[row][line]=11;
return NULL;
}
else 
{
/*

�����Ķ����� ��Ϊ�����Ĳ���ը�� ���� ��������
*/
return NULL;
}

}
void init(int color)
{
  int drive,mode;
  drive=DETECT;
  registerbgidriver(EGAVGA_driver);
  initgraph(&drive,&mode,"");
  setbkcolor(color);


}
void drawrec(int row,int line,int color)
{
                   /*
                   row=1 ��ʼ�� ��Ϊ ����� Ϊ������� ��Χһ��
                   line=1
                   row<=N-2
                   line<=N-2

                   */
                   int y=start_y+(row-1)*LEN+2;
                   int x=start_x+(line-1)*LEN+2;
                   setfillstyle(SOLID_FILL,color);
                   bar(x,y,x+LEN-4,y+LEN-4);


                 }
                 void drawmov(int row,int line,int color)
                 {

                   int y=start_y+(row-1)*LEN;
                   int x=start_x+(line-1)*LEN;
                   setcolor(color);
                   rectangle(x,y,x+LEN,y+LEN);



                 }
                 void drawmap(int kcolor,int color)
                 {
                   int row;
                   setfillstyle(SOLID_FILL,color);
                   bar(start_x,start_y,start_x+(N-1)*LEN,start_y+(N-1)*LEN);
                   setcolor(kcolor);
                   for(row=0;row<N;row++)
                   {
                     line(start_x,start_y+row*LEN,start_x+(N-1)*LEN,start_y+row*LEN);
                     line(start_x+row*LEN,start_y,start_x+row*LEN,start_y+(N-1)*LEN);


                   }


                 }
                 void drawtxt(int row,int line,int color,char *str)
                 {
                   int y=start_y+(row-1)*LEN+LEN/5;
                   int x=start_x+(line-1)*LEN+LEN/5;
                   setcolor(color);
                   outtextxy(x,y,str);
                 }
                 void sign(int row,int line,int color)
                 {
                  int y=start_y+(row-1)*LEN+LEN/5;
                  int x=start_x+(line-1)*LEN+LEN/5;
                  setfillstyle(SOLID_FILL,color);
                  pieslice(x+LEN/2,y+LEN/2,0,360,LEN/3);



                }

