#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode,*LinkList;

Status InitList(LinkList& L)
{
    L=new LNode;
    L->next=L;
    return OK;
}

Status ListInsert(LinkList& L,int i,int e)
{
    LNode* p=L;
    int j=0;
    while (p->next != L && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    LNode* s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

// 删除第 i 个位置的元素
Status ListDelete(LinkList& L, int i) {
    LNode* p = L;
    int j = 0;
    while (p->next != L && j < i - 1) { // 遍历找到 i-1 位置
        p = p->next;
        ++j;
    }
    if (p->next == L || j != i - 1) return ERROR; // 位置不合法

    LNode* q = p->next;
    p->next = q->next;
    delete q;

    return OK;
}

// 获取第 i 个位置的元素
Status GetElem(const LinkList& L, int i, int& e) {
    LNode* p = L->next;
    int j = 1;
    while (p != L && j < i) { // 遍历找到 i 位置
        p = p->next;
        ++j;
    }
    if (p == L || j != i) return ERROR; // 位置不合法
    e = p->data;
    return OK;
}

int* LocateElem(LinkList& L,int v,int& count)
{

}

// 按值查找元素，返回指向该元素的指针
LNode* LocateElem(const LinkList& L, int e) {
    LNode* p = L->next;
    while (p != L && p->data != e) {
        p = p->next;
    }
    return (p == L) ? nullptr : p;
}