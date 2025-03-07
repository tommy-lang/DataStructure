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

// 初始化链表
Status InitList(DuLinkList* L) {
    *L = (DuLinkList)malloc(sizeof(DuLNode)); // 分配头结点内存
    if (!*L) return OVERFLOW; // 内存分配失败
    (*L)->next = *L;
    (*L)->prior = *L;
    return OK;
}

// 插入元素
Status ListInsert_DuL(DuLinkList* L, int i, int e) {
    if (i < 1) return ERROR; // i<1，位置无效
    DuLNode* p = *L;
    int j = 0;
    while ((j < i - 1) && p) {
        p = p->next;
        j++;
    }
    if (j != i - 1) // 指针p没有到达插入位置的前一个结点
        return ERROR;

    DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode)); // 分配新结点
    if (!s) return OVERFLOW; // 内存分配失败
    s->data = e;
    s->next = p->next;
    s->prior = p;
    s->next->prior = s;
    p->next = s;
    return OK;
}

// 删除元素
Status ListDelete_DuL(DuLinkList* L, int i) {
    if (i < 1) return ERROR; // i<1，位置无效
    DuLNode* p = *L;
    int j = 0;
    while ((j < i - 1) && p) {
        p = p->next;
        j++;
    }
    if (j != i - 1) // 指针p没有到达删除位置的前一个结点
        return ERROR;

    DuLNode* q = p->next;
    p->next = q->next;
    if (q->next) {
        q->next->prior = p;
    }
    free(q); // 释放内存
    return OK;
}

// 获取元素
Status GetElem(const DuLinkList L, int i, int* e) {
    DuLNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

// 查找元素
DuLNode* LocateElem(const DuLinkList L, int e) {
    DuLNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

// 测试代码
int main() {
    DuLinkList L;
    if (InitList(&L) == OK) {
        printf("链表初始化成功。\n");

        // 插入元素
        ListInsert_DuL(&L, 1, 10);
        ListInsert_DuL(&L, 2, 20);
        ListInsert_DuL(&L, 3, 30);

        // 获取元素
        int e;
        if (GetElem(L, 2, &e) == OK)
            printf("第2个元素是: %d\n", e);

        // 删除元素
        ListDelete_DuL(&L, 2);

        // 查找元素
        DuLNode* p = LocateElem(L, 20);
        if (p)
            printf("找到了元素: %d\n", p->data);
        else
            printf("没有找到元素 20。\n");
    }

    return 0;
}

