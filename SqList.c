#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct {
    int* elem;
    int length;
} SqList;

// 初始化顺序表
Status InitList(SqList* L) {
    L->elem = (int*)malloc(MAXSIZE * sizeof(int));
    if (!L->elem) {
        printf("Memory allocation failed\n");
        exit(OVERFLOW);
    }
    L->length = 0;
    return OK;
}

// 获取指定位置的元素
Status GetElem(SqList* L, int i, int* e) {
    if (i < 1 || i > L->length)  // 越界检查
        return ERROR;
    *e = L->elem[i - 1];
    return OK;
}

// 查找元素的位次
int LocateElem(SqList* L, int e) {
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == e)
            return i + 1;
    }
    return 0;
}

// 插入元素
Status ListInsert(SqList* L, int i, int e) {
    if (i < 1 || i > L->length + 1)  // 插入位置合法性
        return ERROR;
    if (L->length == MAXSIZE)  // 超过最大长度
        return ERROR;
    for (int j = L->length - 1; j >= i - 1; j--) {
        L->elem[j + 1] = L->elem[j];
    }
    L->elem[i - 1] = e;
    ++L->length;
    return OK;
}

// 删除指定位置的元素
Status ListDelete(SqList* L, int i) {
    if (i < 1 || i > L->length)  // 删除位置合法性
        return ERROR;
    for (int j = i; j < L->length; j++) {
        L->elem[j - 1] = L->elem[j];
    }
    --L->length;
    return OK;
}

int main()
{
    SqList L;
    InitList(&L);  // 初始化顺序表

    // 插入元素
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);
    // 输出顺序表
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    // 查找元素位置
    int pos = LocateElem(&L, 20);
    printf("Element 20 is at position: %d\n", pos);

    // 获取元素
    int elem;
    GetElem(&L, 2, &elem);
    printf("Element at position 2 is: %d\n", elem);

    // 删除元素
    ListDelete(&L, 2);

    // 输出顺序表
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");


    // 释放内存
    free(L.elem);

    return 0;
}
