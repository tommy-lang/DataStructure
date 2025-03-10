#include <iostream>
#include <cstdlib> // exit() 和 malloc()
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct SqList {
    int* elem;
    int length;
} SqList;

Status InitList(SqList* L) {
    L->elem = (int*)malloc(MAXSIZE * sizeof(int)); // 分配空间
    if (!L->elem) {
        printf("Memory Allocation Failed.\n");
        exit(OVERFLOW);
    }
    L->length = 0; // 初始化长度
    return OK;
}

int GetValue(int i, SqList* L) {
    if (i < 1 || i > L->length)
        return ERROR;
    return L->elem[i - 1];
}

// 在一个循环中查找并存储索引
int* SearchValue(int v, SqList* L, int& count) {
    count = 0;
    int* indices = new int[L->length];

    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == v) {
            indices[count++] = i + 1; // 1-based index
        }
    }

    if (count == 0) {
        delete[] indices;
        return nullptr;
    }

    return indices;
}

int InsertValue(int v, int i, SqList* L) {
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (L->length == MAXSIZE)
        return ERROR;
    for (int j = L->length - 1; j >= i - 1; j--) {
        L->elem[j + 1] = L->elem[j];
    }
    L->elem[i - 1] = v;
    ++L->length;
    return OK;
}

int DeleteValue(int i, SqList* L) {
    if (i < 1 || i > L->length)
        return ERROR;
    for (int j = i - 1; j < L->length - 1; j++) {
        L->elem[j] = L->elem[j + 1];
    }
    --L->length;
    return OK;
}

//删除所有值为v的元素，并返回删除后的新数组，使用额外内存
int* DeleteRepeatedElement(SqList* L, int v)
{
    if((*L).length==0)
        return nullptr;
    int count = 0;

    for (int i = 0; i < L->length; i++)
    {
        if (L->elem[i] == v)
        {
            count++;
        }
    }

    if (count == 0)
    {
        return nullptr;
    }

    int* result = new int[(L->length)-count];
    int j = 0;

    for (int i = 0; i < L->length; i++)
    {
        if (L->elem[i]!=v)
        {
            result[j++] = L->elem[i];
        }
    }

    return result;
}

//删除所有值为v的元素，并返回删除后的新数组，不使用额外内存
Status DeleteRepeatedElement(SqList& L, int v)
{
    int j=0;

    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]!=v)
            L.elem[j++]=L.elem[i];
    }

    L.length=j;
    return OK;
}

