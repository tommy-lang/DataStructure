#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

// 队列结点
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode, *QueuePtr;

// 链队列结构
typedef struct {
    QueuePtr front;  // 头指针始终指向头结点
    QueuePtr rear;   // 尾指针指向尾结点
} LinkQueue;

// 初始化链队列
Status InitQueue(LinkQueue* Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));  // 申请头结点
    if (!Q->front)
        return OVERFLOW;
    Q->front->next = NULL;
    return OK;
}

// 队尾插入元素
Status EnQueue(LinkQueue* Q, int e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        return OVERFLOW;
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

// 队头删除元素
Status DeQueue(LinkQueue* Q, int* e) {
    if (Q->front == Q->rear)  // 空队列
        return ERROR;
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)  // 队列删除前只有一个元素结点
        Q->rear = Q->front;
    free(p);
    return OK;
}

// 获取队头元素
int GetHead(const LinkQueue* Q) {
    if (Q->front != Q->rear)  // 不为空队列
        return Q->front->next->data;
    return ERROR;
}

// 释放队列所有结点
void DestroyQueue(LinkQueue* Q) {
    while (Q->front) {
        QueuePtr temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
    Q->rear = NULL;
}

int main() {
    LinkQueue Q;
    InitQueue(&Q);  // 初始化队列

    // 测试入队
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);

    // 获取队列头部元素
    printf("Queue Head: %d\n", GetHead(&Q));

    // 计算队列长度（手动遍历）
    int count = 0;
    QueuePtr p = Q.front->next;
    while (p) {
        count++;
        p = p->next;
    }
    printf("Queue Length: %d\n", count);

    // 测试出队
    int e;
    if (DeQueue(&Q, &e))
        printf("Dequeued Element: %d\n", e);

    // 释放队列内存
    DestroyQueue(&Q);

    return 0;
}
