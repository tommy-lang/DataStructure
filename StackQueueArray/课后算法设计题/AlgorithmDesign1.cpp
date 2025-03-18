#include <iostream>

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

Status InitStack(DblStack& S)
{
    S.v = new int[MAXSIZE];
    S.m = MAXSIZE;
    S.top[0] = -1;
    S.top[1] = S.m;
    S.bot[0] = S.top[0];
    S.bot[1] = S.top[1];
    return OK;
}

bool IsEmpty(const DblStack& S, int stackID)
{
    if(stackID==0)
    {
        return S.top[0]==S.bot[0];
    }
    else
    {
        if(stackID==1)
            return S.top[1] == S.bot[1];
    }
    return false;
}

bool IsFull(const DblStack& S)
{
    return S.top[0] + 1 == S.top[1];
}

Status Push(DblStack& S, int v, int stackID)
{
    if(IsFull(S))
    {
        return ERROR;
    }

    if(stackID==0)
    {
        S.v[++S.top[0]]=v;
    }
    else
    {
        if(stackID==1)
        {
            S.v[--S.top[1]] = v;
        }
        else
        {
            return ERROR;
        }
    }
    return OK;
}

Status Pop(DblStack& S, int stackID)
{
    if(stackID==0)
    {
        if(IsEmpty(S,stackID))
        {
            return ERROR;
        }
        S.top[0]--;
    }
    else
    {
        if(stackID==1)
        {
            if(IsEmpty(S,stackID))
            {
                return ERROR;
            }
            S.top[1]++;
        }
        else
        {
            return ERROR;
        }
    }
    return OK;
}

int main()
{
    DblStack S;
    InitStack(S);

    Push(S, 10, 0);
    Push(S, 20, 0);
    Push(S, 30, 1);
    Push(S, 40, 1);

    std::cout << "Pop from stack 0: " << Pop(S, 0) << std::endl;
    std::cout << "Pop from stack 1: " << Pop(S, 1) << std::endl;

    delete[] S.v;
    return 0;
}

