#include <iostream>
#include <string>

#define MAXSIZE 100

typedef struct
{
    char* base;
    char* top;
    int StackSize;
    int CurrentSize;
} SqStack;

// 初始化栈
void InitStack(SqStack& S)
{
    S.base = new char[MAXSIZE];
    S.top = S.base;
    S.StackSize = MAXSIZE;
    S.CurrentSize=0;
}
