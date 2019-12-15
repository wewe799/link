#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node *next;
}LNode,*LinkList;

/**
 * 链表的初始化函数,用于初始化一条链表(头插法)
 * @return 返回被初始化以后链表的头结点
 */
LinkList createListForHeadInsert(); //链表的初始化

/**
 * 链表逆置函数,用于逆置链表(就地逆置),遍历传入的链表,将每个元素头插至新链的尾部
 * @param head 要逆置的链表的头指针
 * @return 返回被逆置过后的链表
 */
LinkList reverseForInverseSet(LinkList Head);

/**
 * 链表逆置函数,用于逆置链表(使用头插法逆置),遍历传入的链表,将每个元素头插至新链的头部
 * @param head 要逆置的链表的头指针
 * @return 返回被逆置过后的链表
 */
LinkList reverseForHeadInsert(LinkList Head);

/**
 * 用于遍历链表并输出链表元素
 * @param Head 传入的需要遍历的链表头结点
 */
void printList(LinkList Head);


int main() {
    LinkList Head = createListForHeadInsert();//创建链表,返回头指针
    printList(Head);//在逆置之前打印链表
    Head = reverseForHeadInsert(Head);
    //Head = reverseForInverseSet(Head);//进行链表的逆置
    printList(Head);//打印逆置后的链表
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
