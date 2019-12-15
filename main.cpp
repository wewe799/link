#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node *next;
}LNode,*LinkList;

/**
 * ����ĳ�ʼ������,���ڳ�ʼ��һ������(ͷ�巨)
 * @return ���ر���ʼ���Ժ������ͷ���
 */
LinkList createListForHeadInsert(); //����ĳ�ʼ��

/**
 * �������ú���,������������(�͵�����),�������������,��ÿ��Ԫ��ͷ����������β��
 * @param head Ҫ���õ������ͷָ��
 * @return ���ر����ù��������
 */
LinkList reverseForInverseSet(LinkList Head);

/**
 * �������ú���,������������(ʹ��ͷ�巨����),�������������,��ÿ��Ԫ��ͷ����������ͷ��
 * @param head Ҫ���õ������ͷָ��
 * @return ���ر����ù��������
 */
LinkList reverseForHeadInsert(LinkList Head);

/**
 * ���ڱ��������������Ԫ��
 * @param Head �������Ҫ����������ͷ���
 */
void printList(LinkList Head);


int main() {
    LinkList Head = createListForHeadInsert();//��������,����ͷָ��
    printList(Head);//������֮ǰ��ӡ����
    Head = reverseForHeadInsert(Head);
    //Head = reverseForInverseSet(Head);//�������������
    printList(Head);//��ӡ���ú������
}


LinkList createListForHeadInsert() 
{
    LinkList Head= (LinkList)malloc(sizeof(LinkList));
    Head->next = NULL;
    LNode *s;
    int x;

    while(scanf("%d",&x) && x!= -1) {
        s = (LNode*)malloc(sizeof(LNode*));
        s->data = x;
        s->next = Head->next;
        Head->next = s;
    }

    return Head;
}

LinkList reverseForInverseSet(LinkList Head)
{
    LNode *p,*q;
    p = Head->next;
    Head->next = NULL;
    while(p) {
        q = p;
        p = p->next;
        q->next = Head->next;
        Head->next = q;
    }
}

void printList(LinkList Head) 
{

    LNode *p;
    for (p = Head->next;p!=NULL;p = p->next) 
	{
        printf("%d\t",p->data);
    }
    printf("\n");
}

LinkList reverseForHeadInsert(LinkList Head)
{
    LNode *p,*s;
    LinkList newHead = (LinkList)malloc(sizeof(LinkList));
    newHead -> next = NULL;
    for (p = Head->next;p!=NULL;p = p->next) 
	{
        s = (LNode*)malloc(sizeof(LNode*));
        s->data = p->data;
        s->next = newHead->next;
        newHead->next = s;
    }
    return newHead;
}
