#include <iostream>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct
{
    int* base;
    int* top;
    int StackSize;//the MaxSize of the stack;
    int CurrentSize;
}SqStack;

Status InitStack(SqStack& S)
{
    S.base=new int[MAXSIZE];
    if(!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.StackSize=MAXSIZE;
    S.CurrentSize=0;
    return OK;
}

Status Push(SqStack& S,int e)
{
    if(S.top-S.base==MAXSIZE)
        return ERROR;
    *(S.top)=e;
    (S.top)++;
    S.CurrentSize++;
    return OK;
}

Status Pop(SqStack& S,int& e)//逻辑上实现了删除，物理上没有
{
    if(S.top-S.base==0)
        return ERROR;
    (S.top)--;
    e=*(S.top);
    S.CurrentSize--;
    return OK;
}

Status GetTop(SqStack& S,int& e)
{
    if(S.top-S.base==0)
        return ERROR;
    e=*(--S.top);
    return OK;
}

void PrintStack(SqStack& S)
{
    for(int i=0;i<S.CurrentSize;i++)
    {
        std::cout<<S.base[i]<<" ";
    }
}

int main()
{
    SqStack S;
    InitStack(S);
    Push(S,1);
    Push(S,2);
    Push(S,3);
    Push(S,4);
    Push(S,5);
    Push(S,6);
    PrintStack(S);
    return 0;
}