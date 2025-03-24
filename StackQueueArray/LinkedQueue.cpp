#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW (-2)

typedef int Status;

typedef struct QNode
{
    int data;
    struct QNode* next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front;//头指针始终指向头结点
    QueuePtr rear;//尾指针指向尾结点
}LinkQueue;

Status InitQueue(LinkQueue& Q)
{
    Q.front=Q.rear=new QNode;
    Q.front->next= nullptr;
    return OK;
}

Status EnQueue(LinkQueue& Q,int e)//队尾插入
{
    QNode* p=new QNode;
    p->data=e;
    p->next=nullptr;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

Status DeQueue(LinkQueue& Q,int& e)//队头删除
{
    if(Q.front==Q.rear)//空队列
        return ERROR;
    QNode* p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)//队列在删除前只有一个元素结点，此时删除完后已经没有结点了.
        Q.rear=Q.front;
    delete p;
    return OK;
}

int GetHead(const LinkQueue& Q)
{
    if(Q.front!=Q.rear)//不为空队列
        return Q.front->next->data;
    return ERROR;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);

    cout << "Enqueue elements: 10, 20, 30" << endl;
    EnQueue(Q, 10);
    EnQueue(Q, 20);
    EnQueue(Q, 30);

    cout << "Front element: " << GetHead(Q) << endl;

    int e;
    DeQueue(Q, e);
    cout << "Dequeued element: " << e << endl;
    cout << "New front element: " << GetHead(Q) << endl;

    DeQueue(Q, e);
    cout << "Dequeued element: " << e << endl;
    cout << "New front element: " << GetHead(Q) << endl;

    DeQueue(Q, e);
    cout << "Dequeued element: " << e << endl;

    if (DeQueue(Q, e) == ERROR) {
        cout << "Queue is empty!" << endl;
    }

    return 0;
}
