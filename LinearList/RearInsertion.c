#include<stdio.h>
#include<stdlib.h>
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
void CreateList_R(LinkList *L, int n)
{
    *L = (LNode*)malloc(sizeof(LNode));  // 创建头结点
    (*L)->next = NULL;  // 头结点的 next 指向 NULL
    LNode *r = *L;  // r 是尾指针，初始化为头结点
    for (int i = 0; i < n; i++)
    {
        LNode* p = (LNode*)malloc(sizeof(LNode));  // 创建新节点
        scanf_s("%d", &p->data);  // 读取数据
        p->next = NULL;  // 新节点的 next 指向 NULL
        r->next = p;  // 将新节点连接到链表
        r = p;  // 更新尾指针
    }
}