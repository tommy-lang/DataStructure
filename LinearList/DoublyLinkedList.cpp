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

Status ListInsert_DuL(DuLinkList& L, int i, int e)
{
    if (i < 1) return ERROR; // i<1, 位置不存在
    DuLNode* p = L;
    int j = 0;
    while ((j < i - 1) && p)
    {
        p = p->next;
        j++;
    }
    if (!p) return ERROR;  // 如果 p 为空，说明 i 超出范围，插入失败

    DuLNode* s = new DuLNode;
    s->data = e;
    s->next = p->next;
    s->prior = p;
    if (p->next)  // 避免访问 nullptr，这出现在插入尾部时
        p->next->prior = s;
    p->next = s;

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
    DuLNode* q = p->next;           // q指向要删除的节点
    p->next = q->next;              // p指向q的下一个节点

    if (q->next != nullptr)
    {       // 如果q的下一个节点不为空
        q->next->prior = p;         // 更新q的下一个节点的prior指向p
    }

    delete q;                       // 删除节点q
    return OK;
}

void DeleteNodeByValue(DuLinkList& L, int v)
{
    DuLNode* p = L;  // p指向链表的头节点
    while (p->next)  // 遍历链表
    {
        if (p->next->data == v)  // 找到值为 v 的节点
        {
            DuLNode* q = p->next;  // q指向要删除的节点
            p->next = q->next;  // p指向q的下一个节点

            if (q->next != nullptr)  // 如果q的下一个节点不为空
            {
                q->next->prior = p;  // 更新q的下一个节点的prior指向p
            }

            delete q;  // 删除节点q
        }
        else
        {
            p = p->next;  // 继续遍历链表
        }
    }
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