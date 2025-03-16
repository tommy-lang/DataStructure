#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

// 默认队列最大可存储元素为 MAXQSIZE - 1
typedef struct
{
    int* base;   // 存储队列元素的动态数组
    int front;   // 队列头部元素的位置索引
    int rear;    // 队列尾部元素的下一个位置的索引
} SqQueue;

Status InitQueue(SqQueue* Q)
{
    Q->base = (int*)malloc(MAXQSIZE * sizeof(int)); // C 语言用 malloc 申请内存
    if (!Q->base)
        exit(OVERFLOW);  // 申请失败直接退出
    Q->front = Q->rear = 0;
    return OK;
}

int QueueLength(const SqQueue* Q)
{
    return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue* Q, int e)
{
    if ((Q->rear + 1) % MAXQSIZE == Q->front)  // 判断队列是否满
        return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue* Q, int* e)
{
    if (Q->front == Q->rear)  // 判断队列是否空
        return ERROR;
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}

int GetHead(const SqQueue* Q)
{
    if (Q->front == Q->rear)
        return ERROR;
    return Q->base[Q->front];
}

void DestroyQueue(SqQueue* Q)
{
    if (Q->base)
    {
        free(Q->base);
        Q->base = NULL;
    }
}

int main()
{
    SqQueue Q;
    InitQueue(&Q); // 初始化队列

    // 测试入队
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);

    // 获取队列头部元素
    printf("Queue Head: %d\n", GetHead(&Q));

    // 计算队列长度
    printf("Queue Length: %d\n", QueueLength(&Q));

    // 测试出队
    int e;
    if (DeQueue(&Q, &e))
        printf("Dequeued Element: %d\n", e);

    // 释放队列内存
    DestroyQueue(&Q);

    return 0;
}

