#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct LinkList
{
    int data;                  // 数据域
    struct LinkList* next;     // next 指向的是同类型结构体
} LinkList;

// 初始化链表
Status InitList(LinkList** L)
{
    *L = (LinkList*)malloc(sizeof(LinkList));
    if (*L == NULL)
        return OVERFLOW;
    (*L)->next = NULL;
    return OK;
}

// 获取第 i 个元素
Status GetElem(LinkList* L, int i, int* e)
{
    LinkList* p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

// 查找指定元素
LinkList* LocateElem(LinkList* L, int e)
{
    LinkList* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

// 插入元素
Status ListInsert(LinkList* L, int i, const int* e)
{
    LinkList* p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return ERROR;
    LinkList* s = (LinkList*)malloc(sizeof(LinkList));
    if (s == NULL)
        return OVERFLOW;
    s->data = *e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除元素
Status ListDelete(LinkList* L, int i)
{
    LinkList* p = L;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
        return ERROR;
    LinkList* q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

// 释放链表内存
void FreeList(LinkList* L)
{
    LinkList* p = L;
    while (p)
    {
        LinkList* temp = p->next;
        free(p);  // 释放当前节点
        p = temp; // 移动到下一个节点
    }
}

int main()
{
    LinkList* L;
    int e1 = 10, e2 = 20, e3 = 30, e4 = 40, e5 = 50;
    int e; // 用来存储获取到的元素

    // 1. 初始化链表
    if (InitList(&L) == OK)
        printf("Initial worked!\n");
    else
        printf("Initial failed!\n");

    // 2. 插入元素
    ListInsert(L, 1, &e1);
    ListInsert(L, 2, &e2);
    ListInsert(L, 3, &e3);
    ListInsert(L, 4, &e4);
    ListInsert(L, 5, &e5);
    printf("elements yet been inserted:10, 20, 30, 40, 50\n");

    // 3. 获取第 3 个元素
    if (GetElem(L, 3, &e) == OK)
        printf("the third element is: %d\n", e);
    else
        printf("failed to get the third element!\n");

    // 4. 查找元素 30
    LinkList* found = LocateElem(L, 30);
    if (found)
        printf("element 30 found!\n");
    else
        printf("element 30 not found!\n");

    // 5. 删除第 2 个元素
    if (ListDelete(L, 2) == OK)
        printf("the second element deleted!\n");
    else
        printf("failed to delete the second element!\n");

    // 6. 再次获取第 2 个元素（删除后位置变化）
    if (GetElem(L, 2, &e) == OK)
        printf("the second element after deleted: %d\n", e);
    else
        printf("failed to get the second element after deleted!\n");

    // 7. 释放链表
    FreeList(L);
    L = NULL;  // 防止悬空指针

    return 0;
}
