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

Status InitList(LinkList& L)//等价于LNode** L
{
    L=new LNode;//allocate memory.
    L->next= nullptr;
    return OK;
}

Status ListInsert(LinkList& L,int i,int e)
{
    LNode* p=L;//头指针L的值赋值给p,则p现在指向第一个结点
    int j=0;
    while(p&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
        return ERROR;
    LNode* s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

Status ListDelete(LinkList& L,int i)
{
    LNode* p=L;
    int j=0;
    while(p&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||(j>i-1))//插入位置非法
        return ERROR;
    LNode* q=p->next;
    p->next=q->next;
    delete q;
    return OK;
}

Status GetElem(const LinkList& L,int i,int& e)//取值函数:获取第i个结点的数据域的值，然后把这个值赋值给e
{
    LNode* p=L->next;//现在把p指向首元节点.
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

int* LocateElem(LinkList& L, int v, int& count)
{
    if (!L || !L->next)
    {  // 检查链表是否为空或只有头结点
        count = 0;
        return nullptr;
    }

    // 第一次遍历：计算匹配的元素个数
    LNode* p = L->next;
    count = 0;
    int index = 1;
    while (p)
    {
        if (p->data == v) count++;
        p = p->next;
    }

    if (count == 0) return nullptr;  // 没找到，直接返回

    // 第二次遍历：存储匹配的索引
    int* result = new int[count];  // 申请动态数组
    p = L->next;
    index = 1;
    int i = 0;

    while (p)
    {
        if (p->data == v)
        {
            result[i++] = index;  // 记录索引
        }
        p = p->next;
        index++;
    }

    return result;
}

// 释放动态分配的数组
void FreeArray(int* arr)
{
    delete[] arr;
}

void DeleteNodeByValue(LinkList& L, int v)
{
    LNode* p = L;
    while (p->next != nullptr)
    {
        if (p->next->data == v)
        {
            LNode* q = p->next;
            p->next = q->next;
            delete q;
        }
        else
        {
            p = p->next;  // 只有在没有删除节点时，才移动到下一个节点
        }
    }
}

