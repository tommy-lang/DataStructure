#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;
typedef struct DuLNode
{
    int data;
    int count;//记录数据结点个数
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode,*DuLinkList;

Status InitList(DuLinkList& L)
{
    L=new DuLNode ;
    L->count=0;
    L->next=L;
    L->prior=L;
    return OK;
}

Status ListInsert(DuLinkList& L, int i, int e) {
    if (i < 1 || i > L->count + 1) {
        return ERROR; // 返回 ERROR 而不是直接 exit
    }

    DuLNode* p = L;
    int j = 0;
    while (j < i - 1) { // 找到第 i-1 个节点
        p = p->next;
        j++;
    }

    DuLNode* s = new DuLNode;

    s->data = e;
    s->count = 0;

    // 插入操作
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;

    L->count++; // 维护链表长度
    return OK;
}

Status ListDelete(DuLinkList& L, int i) {
    if (i < 1 || i > L->count) { // 检查 i 是否有效
        return ERROR;
    }

    DuLNode* p = L->next; // 从头节点的下一个开始（第 1 个数据节点）
    int j = 1;
    while (j < i) { // 找到第 i 个节点
        p = p->next;
        j++;
    }

    // 修改指针，跳过 p
    p->prior->next = p->next;
    p->next->prior = p->prior;

    delete p; // 释放删除的节点
    L->count--; // 更新链表大小
    return OK;
}

Status GetElem(const DuLinkList& L, int i, int& e) {
    if (i < 1 || i > L->count) { // 检查 i 是否有效
        return ERROR;
    }

    DuLNode* p = L->next; // 从头节点的下一个开始（第 1 个数据节点）
    int j = 1;
    while (j < i) { // 找到第 i 个节点
        p = p->next;
        j++;
    }

    e = p->data; // 获取数据
    return OK;
}

DuLNode* LocateElem(const DuLinkList& L, int e) {
    DuLNode* p = L->next; // 从第一个数据节点开始遍历

    while (p != L) { // 遍历整个双向循环链表
        if (p->data == e) {
            return p; // 找到，返回指针
        }
        p = p->next;
    }

    return nullptr; // 未找到，返回 nullptr
}
