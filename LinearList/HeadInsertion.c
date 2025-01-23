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
void CreateList_H(LinkList* L, int n)//C语言无引用，所以使用指针代替引用
{
    *L = (LNode*)malloc(sizeof(LNode));  // 创建一个头结点
    (*L)->next = NULL;  // 头结点的 next 指向 NULL，链表为空

    for (int i = 0; i < n; i++) {
        LNode* p = (LNode*)malloc(sizeof(LNode));  // 创建一个新节点
        scanf("%d", &(p->data));  // 输入新节点的数据域的数据
        p->next = (*L)->next;  // 新节点的 next 指向当前链表的第一个节点（头结点后面的节点）
        (*L)->next = p;  // 头结点的 next 指向新节点
    }
}
