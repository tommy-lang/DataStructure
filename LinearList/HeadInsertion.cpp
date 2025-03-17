#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode,*LinkList;

Status InitList(LinkList& L)//等价于LNode** L
{
    L=new LNode;//allocate memory.
    L->next= nullptr;
    return OK;
}

void CreateList_H(LinkList& L,int value)
{
    LNode* s=new LNode;
    s->data=value;
    s->next=L->next;
    L->next=s;
}