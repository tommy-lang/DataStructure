#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

// 链栈的top指针指向栈顶结点
typedef struct StackNode
{
    int data;
    struct StackNode* next;
} StackNode, *LinkedStack;

Status InitStack(LinkedStack* S)
{
    *S = NULL;
    return OK;
}

Status Push(LinkedStack* S, int e)
{ // 头部插入
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    if (p == NULL)
    {
        return OVERFLOW;
    }
    p->data = e;
    p->next = *S;
    *S = p;
    return OK;
}

Status Pop(LinkedStack* S, int* e)
{ // 头部删除
    if (*S == NULL)
        return ERROR;
    *e = (*S)->data;
    StackNode* p = *S;
    *S = (*S)->next;
    free(p);
    return OK;
}

int GetTop(const LinkedStack S)
{
    if (S == NULL)
        return ERROR;
    return S->data;
}

void PrintStack(const LinkedStack S)
{
    if (S == NULL)
    {
        printf("no elements in Stack.\n");
        return;
    }
    StackNode* p = S;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    LinkedStack S;
    InitStack(&S);
    Push(&S, 4);
    Push(&S, 3);
    Push(&S, 2);
    Push(&S, 1);
    PrintStack(S);
    return 0;
}

