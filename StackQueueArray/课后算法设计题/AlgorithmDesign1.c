#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct
{
    int top[2], bot[2];
    int* v;
    int m;
} DblStack;

Status InitStack(DblStack* S)
{
    S->v = (int*)malloc(MAXSIZE * sizeof(int));
    if (S->v == NULL) return OVERFLOW; // 处理内存分配失败
    S->m = MAXSIZE;
    S->top[0] = -1;
    S->top[1] = S->m;
    S->bot[0] = S->top[0];
    S->bot[1] = S->top[1];
    return OK;
}

int IsEmpty(const DblStack* S, int stackID)
{
    if (stackID == 0)
        return S->top[0] == S->bot[0];
    else if (stackID == 1)
        return S->top[1] == S->bot[1];

    return 0; // 非法 stackID 视为非空
}

int IsFull(const DblStack* S)
{
    return S->top[0] + 1 == S->top[1];
}

Status Push(DblStack* S, int v, int stackID)
{
    if (IsFull(S)) return ERROR;

    if (stackID == 0)
        S->v[++S->top[0]] = v;
    else if (stackID == 1)
        S->v[--S->top[1]] = v;
    else
        return ERROR;

    return OK;
}

Status Pop(DblStack* S, int stackID)
{
    if (stackID == 0)
    {
        if (IsEmpty(S, stackID)) return ERROR;
        S->top[0]--;
    }
    else if (stackID == 1)
    {
        if (IsEmpty(S, stackID)) return ERROR;
        S->top[1]++;
    }
    else
    {
        return ERROR;
    }
    return OK;
}

int main()
{
    DblStack S;
    InitStack(&S);

    Push(&S, 10, 0);
    Push(&S, 20, 0);
    Push(&S, 30, 1);
    Push(&S, 40, 1);

    printf("Pop from stack 0: %d\n", Pop(&S, 0));
    printf("Pop from stack 1: %d\n", Pop(&S, 1));

    free(S.v); // 释放动态分配的内存
    return 0;
}
