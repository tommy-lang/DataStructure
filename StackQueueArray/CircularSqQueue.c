#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)
typedef int Status;

// 队列结构定义
typedef struct {
    int* base;
    int front;
    int rear;
} SqQueue;

// 初始化队列
Status InitQueue(SqQueue* Q) {
    Q->base = (int*)malloc(MAXQSIZE * sizeof(int));
    if (!Q->base) {
        exit(OVERFLOW);
    }
    Q->front = Q->rear = 0;
    return OK;
}

// 入队操作（队尾插入）
Status EnQueue(SqQueue* Q, int e) {
    if ((Q->rear + 1) % MAXQSIZE == Q->front) {
        return ERROR; // 队列满
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return OK;
}

// 出队操作（队头删除）
Status DeQueue(SqQueue* Q, int* e) {
    if (Q->front == Q->rear) {
        return ERROR; // 队列空
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}

// 按照 FIFO（先进先出）顺序打印队列元素
void PrintQueueFIFO(const SqQueue* Q) {
    if (Q->front == Q->rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = Q->front;
    while (i != Q->rear) {
        printf("%d ", Q->base[i]);
        i = (i + 1) % MAXQSIZE;
    }
    printf("\n");
}

// 释放队列所占的内存
void DestroyQueue(SqQueue* Q) {
    free(Q->base);
    Q->base = NULL;
    Q->front = Q->rear = 0;
}

// 测试代码
int main() {
    SqQueue Q;
    InitQueue(&Q);

    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);
    EnQueue(&Q, 40);

    PrintQueueFIFO(&Q); // 输出：10 20 30 40

    int e;
    DeQueue(&Q, &e);
    printf("Dequeued element: %d\n", e); // 输出：Dequeued element: 10

    PrintQueueFIFO(&Q); // 输出：20 30 40

    DestroyQueue(&Q);
    return 0;
}

