#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;
typedef struct DuLNode {
    int data;
    struct DuLNode* prior;
    struct DuLNode* next;
} DuLNode, *DuLinkList;

// 初始化双向循环链表
Status InitList(DuLinkList* L) {
    *L = (DuLNode*)malloc(sizeof(DuLNode));
    if (!(*L)) return OVERFLOW;
    (*L)->next = *L;
    (*L)->prior = *L;
    return OK;
}

// 在双向链表的第 i 个位置插入元素 e
Status ListInsert_DuL(DuLinkList L, int i, int e) {
    if (i < 1) return ERROR;
    DuLNode* p = L;
    int j = 0;
    while ((j < i - 1) && p) {
        p = p->next;
        j++;
    }
    if (!p) return ERROR;

    DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
    if (!s) return OVERFLOW;
    s->data = e;
    s->next = p->next;
    s->prior = p;
    if (p->next) p->next->prior = s;
    p->next = s;

    return OK;
}

// 删除双向链表的第 i 个元素
Status ListDelete_DuL(DuLinkList L, int i) {
    if (i < 1) return ERROR;
    DuLNode* p = L;
    int j = 0;
    while ((j < i - 1) && p) {
        p = p->next;
        j++;
    }
    if (j != i - 1 || !(p->next)) return ERROR;

    DuLNode* q = p->next;
    p->next = q->next;
    if (q->next) q->next->prior = p;
    free(q);

    return OK;
}

// 获取第 i 个元素的值
Status GetElem(DuLinkList L, int i, int* e) {
    DuLNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    *e = p->data;
    return OK;
}

// 查找链表中值为 e 的结点
DuLNode* LocateElem(DuLinkList L, int e) {
    DuLNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

// 打印链表中的元素
void PrintList(DuLinkList L) {
    DuLNode* p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}



