#include <iostream>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct
{
    int top[2],bot[2];
    int* v;
    int m;
}DblStack;

Status InitStack(DblStack& S)
{
    S.v=new int[MAXSIZE];
    S.m=MAXSIZE;
    S.top[0]=-1;
    S.top[1]=S.m;
    S.bot[0]=S.top[0];
    S.bot[1]=S.bot[1];
    return OK;
}

bool IsEmpty(const DblStack& S)
{
    if(S.top[0]==-1&&S.top[1]==S.m)
        return true;
    return false;
}

bool IsFull(const DblStack& S)
{
    if(S.top[0]+1==S.top[1])
        return true;
    return false;
}

Status Push(DblStack& S,int v1,int v2)
{
    if(IsFull(S))
        return ERROR;

}