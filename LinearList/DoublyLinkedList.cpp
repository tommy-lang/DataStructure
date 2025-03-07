#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;
typedef struct DuLNode
{
    int data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode,*DuLinkList;

Status InitList(DuLinkList& L)
{
    L=new DuLNode;
    L->next=L;
    L->prior=L;
    return OK;
}

Status ListInsert_DuL(DuLinkList& L,int i,int e)
{
    if(i<1) return ERROR;//i<1,位置不存在
    DuLNode* p=L;
    int j=0;
    while((j<i-1)&&p)
    {
        p=p->next;
        j++;
    }
    if(j!=i-1||(p->next==nullptr))//指针p没有到达插入位置的前一个结点
        return ERROR;
    DuLNode* s=new DuLNode;
    s->data=e;
    s->next=p->next;
    s->prior=p;
    s->next->prior=s;
    p->next=s;
    return OK;
}

Status ListDelete_DuL(DuLinkList& L,int i)
{
    if(i<1) return ERROR;
    DuLNode* p=L;
    int j=0;
    while((j<i-1)&&p)
    {
        p=p->next;
        j++;
    }
    if(j!=i-1)
        return ERROR;
    DuLNode* q=p->next;
    p->next=q->next;
    q->next->prior=p;
    delete q;
    return OK;
}

Status GetElem(const DuLinkList& L,int i,int& e)
{
    DuLNode* p=L->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    e=p->data;
    return OK;
}

DuLNode* LocateElem(const DuLinkList& L,int e)
{
    DuLNode* p=L->next;
    while(p&&p->data!=e)
        p=p->next;
    return p;
}