/*
    ��������  ��wintc �����±��� ���Ҳ��Բ �ɹ�
    ��Ҫ˼��
    �  �ȶ� Ҫ������  �ļ�  ����Ԥ����
      1  ���  ɾ��  Ԥ���� ����
      2 ��ɾ�� ע�Ͳ��� �Ͷ���   �س� �ո�
      �ڶ���
        1 ����� ���
        2 �ڶ��ļ��� �ؼ��� ���� ���� ���д���



 */

#include "stdio.h"
#include "conio.h"

        int del_ba(char str[])
        {
int i=0;          /*


������ַ���ɾ������  �ո���



*/
int del;
while(str[i]==' ')
{
 i++;

             /* ����� ���� ���ַ��Ƿ�Ϊ ���ַ� ����  */
}

if(i==0)
{
  return 1;


}
for(del=0;del<=strlen(str)-i;del++)
{
 *(str+del)=*(str+del+i);


}

return 1;
}

void main()

{
/*

�ؼ������� ����strcmp������������ �������ַ���
���� ������
��һ����  ǰ��û�� ���


*/
char *key_word[]={"char","main","int" ,"main","long","float","break",
"else","switch","case","enum","typedof","return","union","const",
"short","continue","for","signed","void","default","goto","sizeof",
"do","if","while","struct","staic"
};

char *ope_word[]={"=","<=","<",">=",">","+","-","*","%","/",">>","<<","==","!=",
"&","^","|","&&","||","++","--","~"
};
char oper[5];
int s_line=0;
char ch;
 /*
 ��ȡ�ļ��ַ�����
   int gd,gm;
 gd=DETECT;
 */


 int bc=0;/* ɾ������Ŀո� */
 FILE *fp;/* ���漴��ҪҪ������ļ�ָ�� */
 FILE *out;  /*  �����һ�鴦���ļ� ��Ҫ����Ϊ ɾ�� ����� �ַ� �س� ע�� ����ո�  */
 FILE   *var;
 FILE *ope;
 char o_file[100]; /*  ������ �� �ļ� ɾ��Ԥ������ ʱ�õ�
  */
/*

��������ļ�ָ��

*/
FILE *sign;
 /*

 ����ؼ���   �ļ�ָ��
 */
 FILE *tmp;
 FILE *save;/*�����ļ�ָ��*/
 FILE *key; /*

 �ؼ��� �ļ�ָ��
 */
 int s_row=0;
 int iskey=1;
 /*
 shezhi

 */

 /*
 ����� �ļ����� ��   ��/�� ��β


 */
 char str[15]="";
 char filename[40];
 printf("Please input filename  and end of '/'  \n");
 while((ch=getch())!='/')
 {
   filename[s_row]=ch;
   printf("%c",filename[s_row]);
   s_row++;



 }
 filename[s_row]='\0';

 s_row=0;

 if((fp=fopen(filename,"r"))==NULL)
 {
   printf("\n\n\n\n \t\t\t The fime name is wrong!");

   getch();
   exit(0);


 }

 tmp=fopen("tmp.dat","w");

 while(!feof(fp))
 {
  fgets(o_file,100,fp);
  del_ba(o_file);
  if(o_file[0]=='#')
{                           /*
del����ba�����ȥ��������  ǰ��ո��
֮�������һ���ַ��Ƿ�Ϊ #
����� ��֤�����Ǹ� Ԥ���������
���� ��ȥ

ȥ��Ԥ������


*/
continue;
}
else
{
  fputs(o_file,tmp);

}


}
fclose(fp);
fclose(tmp);
out=fopen("saveda.dat","w");
tmp=fopen("tmp.dat","r");
while((ch=fgetc(tmp))!=EOF)
{
 if(ch=='/')
 {
   save=tmp;
   if(fgetc(save)=='*')
   {
     while(fgetc(tmp)!='*'||fgetc(tmp)!='/')
     {

   /*


 ȥ��ע�� ���� ԭ��
 ���£�
 ������� �ַ� Ϊ  /
 �  ����¸��ַ��Ƿ�Ϊ *
 ������� �� ��Ϊ ���Ǹ�ע��
 ��ѽ�Ƚ���ѭ�� ֱ������ *  /
 ������ ����Ϊ ע�ͽ���

*/

}

ch=fgetc(tmp);


}


}

else if(ch=='\n')
{

 fputc(' ',out);

  /*
         if(!bc&&ch==' ')
         {
         fputc(ch,out);

         bc=1;  ԭ������

           ���� � �׸��ո�֮��  ���׸��ո� �����ļ� ���Ժ�Ŀո�� ���룬
           ���ˣ�֪����������ַ� ��������



         }
           */

       }
       else  if(ch==' ')
       {
         fputc(ch,out);
         while((ch=fgetc(tmp))==' ')
         {



         }
         fputc(ch,out);


       }

       else
       {
     /* bc=0;

     */
        fputc(ch,out);

      }


    }
    remove("tmp.dat");
 /*  ɾ���ļ�
 */
    fclose(tmp);
    fclose(out);
    out=fopen("saveda.dat","r");
    sign=fopen("sign.dat","w");

 /*

 ���� ����� ��Ҫ �����ַ����� ����


 */
 var=fopen("var.dat","w");
 while((ch=fgetc(out))!=EOF)
 {
   if(ch==34)
    {      /*

    34 �� ����assic��ֵ





    */
    fprintf(sign,"< %c,->\t",ch);

    while((ch=fgetc(out))!=34&&ch!=EOF)
    {


    }
    ;
      /*

      � ������� " ��֤�����Ǹ�� �ַ��� �涨
      ��ֱ��Ѱ�ҵ��ַ���   �����ַ� "
      ����ѭ��

      */

      fprintf(sign,"<%c ,->\t",ch);

    }

    if(ch=='\'')
      { fprintf(sign,"<%c ,->         ",ch);
    while((ch=fgetc(out))!='\''&&ch!=EOF)
    {

    }
    fprintf(sign,"<%c ,->   ",ch);

  }
  if(ch=='('||ch==')'||ch=='['||ch==']'||ch=='{'||ch=='}'||ch==';'||ch==',')
  {
                 /*
                  fputc('<',sign);
                  fputc(ch,sign);
                  fputc('��',sign);
                  fputc('>',sign);
                   */

                  fprintf(sign,"< %c,->   ",ch);
                }




              }
              fclose(sign);
              rewind(out);
 key=fopen("key.dat","w"); /*

 �� key��dat����ļ� ֮��Ϊ��д
 ��ר��



 */
 ope=fopen("oper.dat","w");


 /*

 ��Ҫ������

 */
 while((ch=fgetc(out))!=EOF)
 {
   if(ch=='\"')
   {

     while((ch=fgetc(out))!=EOF&&ch!='\"')
     {
       str[s_row]=ch;

       s_row++;
     }

     str[s_row]='\0';
     fprintf(var,"<\"%s\",string>    ",str);
     s_row=0;

   }
   if(ch=='\'')
    {      s_row=0;

      while((ch=fgetc(out))!='\''&&ch!=EOF)
      {
        str[s_row]=ch;


        s_row++;
      }
      str[s_row]='\0';
      getch();


      fprintf(var,"<%s ,str_char>",str);
      fprintf(sign,"<%c ,->   ",ch);
      s_row=0;



    }
    if(ch=='='||ch=='>'||ch=='<'||ch=='+'||ch=='-'||ch=='*'||ch=='%'||ch=='/'||ch=='&'||ch=='|'||ch=='!'||ch=='~')
     {oper[s_line]=ch;

   /*while(((ch=fgetc(out))!=EOF)|(ch=='='||ch=='>'||ch=='<'||ch=='+'||ch=='-'||ch=='*'||ch=='%'||ch=='/'||ch=='&'||ch=='|'||ch=='!'||ch=='~'))
         {       printf("%c",ch);
              s_line++;
              oper[s_line]=ch;


         }
     */

         save=out;
     ch=fgetc(out);  /*

     �����Ԥ�ȴ����ַ��ź��� ���¸�������ʲô
     ��������� ���������
     ���Ż�ָ��
     ���� ��
     ���� ָ��  ��Ϊ�����ֻ�������ַ�


     */
     if(ch=='='||ch=='>'||ch=='<'||ch=='+'||ch=='-'||ch=='*'||ch=='%'||ch=='/'||ch=='&'||ch=='|'||ch=='!'||ch=='~')
     {
      oper[++s_line]=ch;

    }
    else
    {

     fseek(out,-1,SEEK_CUR);

   }
   oper[++s_line]='\0';

   for(s_line=0;s_line<28;s_line++)
   {

     if(strcmp(oper,ope_word[s_line])==0)
     {

       fprintf(ope,"<%s,ope>   ",oper);

     }

   }
   s_line=0;

   if(strcmp(oper,"=")==0)
   {

     while((ch=fgetc(out))!=EOF&&(ch!=';'&&ch!='('))
     {
       o_file[s_line]=ch;
       s_line++;
     }
     o_file[s_line]='\0';

     fseek(out,-1,SEEK_CUR);
     s_line=0;
     if(ch=='(')
     {
      fprintf(var,"<%s,var>    ",o_file);


    }
    else
    {

     fprintf(var,"<%s,string>    ",o_file);
   }
 }

}

if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
{

str[s_row]=ch;          /*

�����ʱ� ������

*/
while((ch=fgetc(out))!=EOF&&((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||ch=='_'||(ch>='0'&&ch<='9')))
{
  s_row++;
  str[s_row]=ch;

}
fseek(out,-1,SEEK_CUR);
str[s_row+1]='\0';
for(s_row=0;s_row<27;s_row++)
{

  if(strcmp(str,key_word[s_row])==0)
   {fprintf(key,"<%s,->    ",str);
       iskey=0;            /*

       iskey �Ǹ���־λ ����� �ؼ���
       �� ��0
       ��ʾ���Ǹ��ؼ����Ѵ���
       */
       break;
     }


   }
   if(iskey)
    fprintf(var,"<%s,var>    ",str);
  iskey=1;
  s_row=0;


}

}
fclose(key);
fclose(ope);
fclose(fp);
fclose(out);
fclose(var);
textcolor(BLUE);
textbackground(WHITE);
  /*

  ��� text textcolor
  ֮������ʹ�� highvideo����
  ��������ɳ�ͻ


  */
  while(1)
   { printf("\n\n\t\tpress any key!!go on!\n");
 getch();
 clrscr();

 printf("\nWrok is over ,please choese a choice for youself\n");
 printf("1   the key  word\n");
 printf("2   the sign word\n");
 printf("3   the var  word\n");
 printf("4   the ope  word\n");
 printf("q   exit widow!   \n");

 ch=getch();
 printf("\n \t \tYour choice   :%c \n\n\t\t\tplease press Enter",ch);
 getch();



 switch(ch)
   {                         /*



   �ⲿ��Ϊ �������


   */
   case 'q':exit(0);break;
   case '1':clrscr();
   printf("the key word  :\n");
   out=fopen("key.dat","r");
   while(!feof(out))
               {  fgets(o_file,100,out);  /*


               ���ж��� ���

               */
               printf("%s",o_file);

             }
             fclose(out);break;
             case '2':clrscr();
             printf("the sign word  :\n");
             out=fopen("sign.dat","r");
             while(!feof(out))
               {  fgets(o_file,100,out);
                 printf("%s",o_file);

               }
               fclose(out); break;
               case '3':clrscr();printf("the var word  :\n");out=fopen("var.dat","r");
               while(!feof(out))
                 {  fgets(o_file,100,out);
                   printf("%s",o_file);

                 }
                 fclose(out);break;
                 case '4':clrscr();printf("the operator word  :\n");out=fopen("oper.dat","r");
                 while(!feof(out))
                   {  fgets(o_file,100,out);
                     printf("%s",o_file);

                   }
                   fclose(out);break;
                   default :break;
                 }




               }
               getch();


             }
