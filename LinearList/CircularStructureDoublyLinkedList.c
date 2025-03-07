#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

// 双向循环链表节点结构
typedef struct DuLNode {
    int data;
    int count; // 记录数据结点个数
    struct DuLNode* prior;
    struct DuLNode* next;
} DuLNode, *DuLinkList;

// 初始化链表
Status InitList(DuLinkList* L) {
    *L = (DuLNode*)malloc(sizeof(DuLNode));
    if (*L == NULL) return OVERFLOW;

    (*L)->count = 0;
    (*L)->next = *L;
    (*L)->prior = *L;
    return OK;
}

// 插入节点
Status ListInsert(DuLinkList L, int i, int e) {
    if (i < 1 || i > L->count + 1) {
        return ERROR;
    }

    DuLNode* p = L;
    int j = 0;
    while (j < i - 1) { // 找到第 i-1 个节点
        p = p->next;
        j++;
    }

    DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
    if (s == NULL) return OVERFLOW; // 内存分配失败

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

// 删除节点
Status ListDelete(DuLinkList L, int i) {
    if (i < 1 || i > L->count) {
        return ERROR;
    }

    DuLNode* p = L->next; // 从第一个数据节点开始
    int j = 1;
    while (j < i) { // 找到第 i 个节点
        p = p->next;
        j++;
    }

    // 修改指针，跳过 p
    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(p); // 释放删除的节点
    L->count--; // 更新链表大小
    return OK;
}

// 获取第 i 个元素
Status GetElem(DuLinkList L, int i, int* e) {
    if (i < 1 || i > L->count) {
        return ERROR;
    }

    DuLNode* p = L->next; // 从第一个数据节点开始
    int j = 1;
    while (j < i) {
        p = p->next;
        j++;
    }

    *e = p->data; // 获取数据
    return OK;
}

// 查找值为 e 的节点
DuLNode* LocateElem(DuLinkList L, int e) {
    DuLNode* p = L->next; // 从第一个数据节点开始

    while (p != L) { // 遍历整个双向循环链表
        if (p->data == e) {
            return p; // 找到，返回指针
        }
        p = p->next;
    }

    return NULL; // 未找到，返回 NULL
}

// 释放链表
void DestroyList(DuLinkList L) {
    DuLNode* p = L->next;
    while (p != L) {
        DuLNode* temp = p;
        p = p->next;
        free(temp);
    }
    free(L);
}

// 遍历链表并打印
void PrintList(DuLinkList L) {
    DuLNode* p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 主函数测试
int main() {
    DuLinkList L;
    InitList(&L);

    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ListInsert(L, 2, 15);

    printf("链表元素: ");
    PrintList(L);

    int value;
    if (GetElem(L, 2, &value) == OK) {
        printf("第 2 个元素是: %d\n", value);
    }

    ListDelete(L, 3);
    printf("删除第 3 个元素后: ");
    PrintList(L);

    DuLNode* node = LocateElem(L, 20);
    if (node) {
        printf("找到元素 20\n");
    } else {
        printf("未找到元素 20\n");
    }

    DestroyList(L);
    return 0;
}

