#include<iostream>

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;

//默认队列最大可存储元素为MAXQSIZE-1
typedef struct
{
    int* base;
    int front;//队列头部元素的位置索引
    int rear;//队列尾部元素的下一个位置的索引
}SqQueue;

Status InitQueue(SqQueue& Q)
{
    Q.base=new int[MAXQSIZE];
    if(!Q.base)
        exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}

int QueueLength(const SqQueue& Q)
{
    return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

Status EnQueue(SqQueue& Q,int e)//尾部插入
{
    if((Q.rear+1)%MAXQSIZE==Q.front)
        return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue& Q,int& e)
{
    if(Q.front==Q.rear)
        return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}

int GetHead(const SqQueue& Q)
{
    if(Q.front==Q.rear)
        return ERROR;
    return Q.base[Q.front];
}
