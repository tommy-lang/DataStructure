#include<iostream>

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;
//默认队列最大可存储元素为MAXQSIZE-1
//队列的特点为队头插入，队尾删除
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
    return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;//这是为了解决C语言中负数(Q.rear-Q.front)可能小于0
    // 进行mod运算时可能不会得到数学上的模运算的结果，
    //另外即使Q.rear-Q.front为正数，但是加上MAXQSIZE后它和Q.rear-Q.front为同余关系，模运算结果一样。
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

void PrintQueueFIFO(const SqQueue& Q)
{
    if (Q.front == Q.rear)
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << "Queue elements: ";
    for (int i = Q.front; i != Q.rear; i = (i + 1) % MAXQSIZE)
    {
        std::cout << Q.base[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    SqQueue Q;
    InitQueue(Q);

    EnQueue(Q, 10);
    EnQueue(Q, 20);
    EnQueue(Q, 30);
    EnQueue(Q, 40);

    PrintQueueFIFO(Q);  // 输出：10 20 30 40

    int e;
    DeQueue(Q, e);
    PrintQueueFIFO(Q);  // 输出：20 30 40

    return 0;
}