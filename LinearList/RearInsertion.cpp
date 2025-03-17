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

void CreateList_R1(LinkList& L,int value)//没有设置尾指针的尾插法
{
    LNode* p=L;
    while(p->next!= nullptr)
    {
        p=p->next;
    }
    LNode* s=new LNode;
    s->data=value;
    s->next=p->next;
    p->next=s;
}

void CreateList_R2(LinkList& L,int n)//设置尾指针的尾插法,假设传入的是空链表
{
    L=new LNode;
    L->next=nullptr;
    LNode* r=L;
    for(int i=0;i<n;i++)
    {}
    LNode* p=new LNode;
    std::cin>>p->data;
    p->next=nullptr;
    r->next=p;
    r=p;
}

