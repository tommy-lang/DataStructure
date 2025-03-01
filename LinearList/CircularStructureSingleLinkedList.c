#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;

struct LNode {
    int data;
    struct LNode* next;
};

// 初始化循环链表
Status InitList(struct LNode** L) {
    *L = (struct LNode*)malloc(sizeof(struct LNode));
    if (!(*L)) return OVERFLOW;
    (*L)->next = *L; // 头节点指向自身，形成循环
    return OK;
}

// 在第 i 个位置插入元素 e
Status ListInsert(struct LNode* L, int i, int e) {
    struct LNode* p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        ++j;
    }
    struct LNode* s = (struct LNode*)malloc(sizeof(struct LNode));
    if (!s) return OVERFLOW;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除第 i 个位置的元素
Status ListDelete(struct LNode* L, int i) {
    struct LNode* p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p->next == L || j != i - 1) return ERROR; // 位置不合法

    struct LNode* q = p->next;
    p->next = q->next;
    free(q);

    return OK;
}

// 获取第 i 个位置的元素
Status GetElem(struct LNode* L, int i, int* e) {
    struct LNode* p = L->next;
    int j = 1;
    while (p != L && j < i) {
        p = p->next;
        ++j;
    }
    if (p == L || j != i) return ERROR; // 位置不合法
    *e = p->data;
    return OK;
}

// 按值查找元素，返回指向该元素的指针
struct LNode* LocateElem(struct LNode* L, int e) {
    struct LNode* p = L->next;
    while (p != L && p->data != e) {
        p = p->next;
    }
    return (p == L) ? NULL : p;
}

// 打印循环链表（不包含头节点）
void PrintList(struct LNode* L) {
    struct LNode* p = L->next;
    while (p != L) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("(Loop back to head)\n");
}

// 释放链表
void DestroyList(struct LNode* L) {
    struct LNode* p = L->next;
    while (p != L) {
        struct LNode* temp = p;
        p = p->next;
        free(temp);
    }
    free(L);
}

// 测试代码
int main() {
    struct LNode* L;
    InitList(&L);

    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);

    printf("循环链表内容：\n");
    PrintList(L);

    int e;
    if (GetElem(L, 2, &e) == OK)
        printf("第 2 个元素的值是 %d\n", e);

    if (ListDelete(L, 2) == OK)
        printf("删除第 2 个元素后：\n");
    PrintList(L);

    DestroyList(L);
    return 0;
}
