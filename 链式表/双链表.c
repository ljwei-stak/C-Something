#include <stdio.h>
#include <stdlib.h>
typedef struct line{
    struct line * prior;
    int data;
    struct line * next;
}line;
line* initLine(line * head);
line * insertLine(line * head,int data,int add);
line * delLine(line * head,int data);
void display(line * head);
int main() {
    line * head=NULL;
    head=initLine(head);
   
    head=insertLine(head, 4, 2);
    display(head);
    head=delLine(head, 2);
    display(head);
   
    return 0;
}
line* initLine(line * head){
    head=(line*)malloc(sizeof(line));
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    line * list=head;
    for (int i=2; i<=3; i++) {
        line * body=(line*)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;
       
        list->next=body;
        body->prior=list;
        list=list->next;
    }
    return head;
}
line * insertLine(line * head,int data,int add){
    //�½�������Ϊdata�Ľ��
    line * temp=(line*)malloc(sizeof(line));
    temp->data=data;
    temp->prior=NULL;
    temp->next=NULL;
    //���뵽����ͷ��Ҫ���⿼��
    if (add==1) {
        temp->next=head;
        head->prior=temp;
        head=temp;
    }else{
        line * body=head;
        //�ҵ�Ҫ����λ�õ�ǰһ�����
        for (int i=1; i<add-1; i++) {
            body=body->next;
        }
        //�ж�����Ϊ�棬˵������λ��Ϊ����β
        if (body->next==NULL) {
            body->next=temp;
            temp->prior=body;
        }else{
            body->next->prior=temp;
            temp->next=body->next;
            body->next=temp;
            temp->prior=body;
        }
    }
    return head;
}
line * delLine(line * head,int data){
    line * temp=head;
    //��������
    while (temp) {
        //�жϵ�ǰ������������data�Ƿ���ȣ�����ȣ�ժ���ý��
        if (temp->data==data) {
            temp->prior->next=temp->next;
            temp->next->prior=temp->prior;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    printf("�������޸�����Ԫ��");
    return head;
}
//�������Ĺ��ܺ���
void display(line * head){
    line * temp=head;
    while (temp) {
        if (temp->next==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
}